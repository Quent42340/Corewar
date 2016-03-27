/*
** run.c for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Thu Mar 24 13:00:44 2016 Jakob Kellendonk
** Last update Sun Mar 27 17:25:32 2016 Jakob Kellendonk
*/

#include "run.h"
#include "vm_copy.h"

int		get_cycle_amount(unsigned char *cmd)
{
  int		i;
  int		offset;

  offset = 2;
  if (cmd[0] <= 0 || cmd[0] > 16)
    return (1);
  i = 0;
  while ((cmd[0] != 1 && cmd[0] != 9 && cmd[0] != 12 && cmd[0] != 15)
	 && i < op_tab[cmd[0] - 1].nbr_args)
    {
      if ((!((cmd[1] >> (6 - 2 * i)) & 3)
	   || !(op_tab[cmd[0] - 1].type[i]
		& (((((cmd[1] >> (6 - 2 * i)) & 3) == 1) * T_REG
		    | (((cmd[1] >> (6 - 2 * i)) & 3) == 2) * T_DIR
		    | (((cmd[1] >> (6 - 2 * i)) & 3) == 3) * T_IND)))
	   || (((cmd[1] >> (6 - 2 * i)) == 1)
	       && (cmd[offset] > 16 || cmd[offset] < 1))))
	return (1);
      offset = offset + ((cmd[1] >> (6 - 2 * i)) == 1)
	+ ((cmd[1] >> (6 - 2 * i)) == 2) * DIR_SIZE
	+ ((cmd[1] >> (6 - 2 * i)) == 3) * IND_SIZE;
      i = i + 1;
    }
  return (op_tab[cmd[0] - 1].nbr_cycles);
}

t_err		execute(t_application *application, t_process **process)
{
  t_func	funcs[16];

  write(1, "executing ", 10);
  my_putstr_out(op_tab[(*process)->cmd[0] - 1].mnemonique, 1);
  write(1, "\n", 1);
  funcs[0] = &instruction_live;
  funcs[1] = &instruction_ld;
  funcs[2] = &instruction_st;
  funcs[3] = &instruction_add;
  funcs[4] = &instruction_sub;
  funcs[5] = &instruction_and;
  funcs[6] = &instruction_or;
  funcs[7] = &instruction_xor;
  funcs[8] = &instruction_zjmp;
  funcs[9] = &instruction_ldi;
  funcs[10] = &instruction_sti;
  funcs[11] = &instruction_fork;
  funcs[12] = &instruction_lld;
  funcs[13] = &instruction_lldi;
  funcs[14] = &instruction_lfork;
  funcs[15] = &instruction_aff;
  return (funcs[(*process)->cmd[0] - 1](application, process));
}

t_err	update_process(t_application *application, t_process *process)
{
  t_err	error;

  if (process->cycles_left == 1)
    {
      if ((error = execute(application, &process)))
	return (error);
    }
  else if (process->cycles_left == 0)
    {
      vm_cpyfrom(application, process->pc, process->cmd, CMD_MAX_SIZE);
      process->cycles_left = get_cycle_amount(process->cmd);
      if (process->cycles_left == 1)
	process->pc = process->pc + 1;
    }
  process->cycles_left = process->cycles_left - 1;
  return (0);
}

t_err	remove_dead(t_application *app)
{
  int	i;
  int	alive;
  int	last_live;

  last_live = 0;
  alive = 0;
  i = -1;
  while (++i < app->program_amount)
    {
      if (app->programs[i].is_alive && !app->programs[i].did_live
	  && app->death_callback)
	app->death_callback(app, app->programs + i);
      if (app->programs[i].is_alive && !app->programs[i].did_live)
	app->programs[i].is_alive = 0;
      app->programs[i].did_live = 0;
      alive = alive + app->programs[i].is_alive;
      if (last_live < app->programs[i].last_live_cycle)
	last_live = app->programs[i].last_live_cycle;
    }
  i = -1;
  while (alive <= 1 && ++i < app->program_amount)
    if (last_live == app->programs[i].last_live_cycle)
      message_win(&app->programs[i], i);
  app->last_limit_hit = app->cycle;
  return (ERROR_UNKNOWN * (alive <= 1));
}

t_err	tick(t_application *application)
{
  int	i;
  int	j;
  t_err	err;

  if (application->cycle - application->last_limit_hit
      >= application->cycle_to_die && (err = remove_dead(application)))
    return (err);
  if (application->cycle == application->constants->dump_cycle)
    return (dump_vm(application));
  i = -1;
  while (++i < application->program_amount)
    {
      if (application->programs[i].is_alive)
	{
	  j = -1;
	  while (++j < application->programs[i].process_amount)
	    if ((err = update_process(application,
				      application->programs[i].processes + j)))
	      return (err);
	}
    }
  application->cycle = application->cycle + 1;
  return (0);
}
