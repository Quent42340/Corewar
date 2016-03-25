/*
** instructions_fork.c for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/source/run
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Thu Mar 24 17:29:08 2016 Flora Huot
** Last update Fri Mar 25 18:06:41 2016 Jakob Kellendonk
*/

#include <stdlib.h>
#include "instructions.h"
#include "my_mem.h"

t_err		new_process(t_process *old, int newpc)
{
  t_process	*new;

  old->parent->process_amount = old->parent->process_amount + 1;
  old->parent->processes = realloc(old->parent->processes,
				   sizeof(t_process) * old->parent->process_amount);
  if (!old->parent->processes)
    return (ERROR_MALLOC_FAILED);
  new = old->parent->processes + old->parent->process_amount - 1;
  my_memcpy(new, old, sizeof(t_process));
  new->pc = ((newpc % MEM_SIZE) + MEM_SIZE) % MEM_SIZE;
  new->cycles_left = new->cycles_left + 1;
  return (0);
}

t_err	instruction_fork(t_application *app, t_process *proc)
{
  t_err	err;

  (void)app;
  if ((err = new_process(proc, proc->pc + char_to_short(proc->cmd + 1) % IDX_MOD)))
    return (err);
  proc->pc = proc->pc + 3;
  return (0);
}

t_err	instruction_lfork(t_application *app, t_process *proc)
{
  t_err	err;

  (void)app;
  if ((err = new_process(proc, proc->pc + char_to_short(proc->cmd + 1))))
    return (err);
  proc->pc = proc->pc + 3;
  return (0);
}
