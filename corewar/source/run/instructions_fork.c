/*
** instructions_fork.c for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/source/run
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Thu Mar 24 17:29:08 2016 Flora Huot
** Last update Tue Mar 29 18:23:22 2016 Jakob Kellendonk
*/

#include <stdlib.h>
#include "application.h"
#include "my_mem.h"
#include "run.h"

t_err		new_process(t_process **old, int newpc)
{
  t_process	*new;
  t_program	*parent;
  int		offset;

  parent = (*old)->parent;
  parent->process_amount = parent->process_amount + 1;
  offset = *old - parent->processes;
  parent->processes = realloc(parent->processes,
			      sizeof(t_process) * parent->process_amount);
  if (!parent->processes)
    return (print_error(ERROR_MALLOC_FAILED));
  *old = offset + parent->processes;
  new = parent->processes + parent->process_amount - 1;
  my_memcpy(new, *old, sizeof(t_process));
  new->pc = ((newpc % MEM_SIZE) + MEM_SIZE) % MEM_SIZE;
  new->cycles_left = 0;
  return (0);
}

t_err	instruction_fork(t_application *app, t_process **proc)
{
  t_err	err;

  (void)app;
  if ((err = new_process(proc, (*proc)->pc
			 + char_to_short((*proc)->cmd + 1) % IDX_MOD)))
    return (err);
  (*proc)->pc = (*proc)->pc + 3;
  return (0);
}

t_err	instruction_lfork(t_application *app, t_process **proc)
{
  t_err	err;

  (void)app;
  if ((err = new_process(proc, (*proc)->pc + char_to_short((*proc)->cmd + 1))))
    return (err);
  (*proc)->pc = (*proc)->pc + 3;
  return (0);
}
