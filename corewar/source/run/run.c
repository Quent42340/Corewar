/*
** run.c for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Thu Mar 24 13:00:44 2016 Jakob Kellendonk
** Last update Thu Mar 24 17:57:46 2016 Jakob Kellendonk
*/

#include "run.h"

t_err	update_process(t_application *application, t_process *process)
{
  int	error;

  if (process->cycles_left == 0)
    {
      vm_cpyfrom(application, process->cmd, CMD_MAX_SIZE);
      process->cycles_left = GET_CYLCLE_AMOUNT(process);
    }
  if (process->cycles_left == 1)
    {
      if ((error = execute(application, process)))
	return (error);
    }
  process->cycles_left = process->cycles_left - 1;
  return (0);
}

t_err	tick(t_application *application)
{
  int	i;
  int	j;
  t_err	r;

  i = 0;
  while (i < application->program_amount)
    {
      j = 0;
      while (j < application->programs[i].process_amount)
	{
	  if (r = update_process(application, application->programs[i].processes + j))
	    return (r);
	  j = j + 1;
	}
      i = i + 1;
    }
  application->cycle = application->cycle + 1;
  return (0);
}
