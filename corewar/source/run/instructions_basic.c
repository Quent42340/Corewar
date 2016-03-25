/*
** instructions_basic.c for corewar in corewar/source/run
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Thu Mar 24 17:27:26 2016 Flora Huot
** Last update Fri Mar 25 18:07:42 2016 Jakob Kellendonk
*/

#include "instructions.h"
#include "my_mem.h"

t_err	instruction_live(t_application *app, t_process *proc)
{
  int	i;

  i = 0;
  while (i < app->program_amount)
    {
      app->programs[i].did_live = app->programs[i].did_live
	|| (app->programs[i].live[0] == proc->cmd[0]
	    && app->programs[i].live[1] == proc->cmd[1]
	    && app->programs[i].live[2] == proc->cmd[2]
	    && app->programs[i].live[3] == proc->cmd[3]);
      i = i + 1;
    }
  app->live_count = app->live_count + 1;
  if (app->live_count == app->constants->nbr_live)
    {
      app->live_count = 0;
      app->cycle_to_die = app->cycle_to_die - app->constants->cycle_delta;
    }
  proc->pc = proc->pc + 5;
  return (0);
}

t_err	instruction_zjmp(t_application *app, t_process *proc)
{
  (void)app;
  proc->pc = (((proc->pc + (char_to_short(proc->cmd + 1) % IDX_MOD))
	       % MEM_SIZE) + MEM_SIZE) % MEM_SIZE;
  return (0);
}

t_err		instruction_aff(t_application *app, t_process *proc)
{
  unsigned char	c;

  (void)app;
  c = (unsigned char)(((char_to_int(proc->cmd + 2) % 255) + 255) % 255);
  write(1, &c, 1);
  return (0);
}
