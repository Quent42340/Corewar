/*
** instructions_ld.c for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/source/run
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Thu Mar 24 17:26:58 2016 Flora Huot
** Last update Fri Mar 25 15:37:44 2016 Jakob Kellendonk
*/

#include "instructions.h"
#include "vm_copy.h"

t_err		instruction_ld(t_application *app, t_process *proc)
{
  unsigned char	buff[4];
  unsigned char	*buffs[2];
  unsigned char	fmt;

  fmt = proc->cmd[1];
  buffs[1] = proc->cmd + 2;
  buffs[0] = buff;
  buffs[1] = get_args(app, proc, (fmt >> 6) & 3, buffs);
  proc->carry = !char_to_int(buffs[0]);
  buffs[1] = set_args(app, proc, (fmt >> 4) & 3, buffs);
  proc->pc = (proc->pc + buffs[1] - proc->cmd) % MEM_SIZE;
  return (0);
}

t_err		instruction_ldi(t_application *app, t_process *proc)
{
  unsigned char	read[2][4];
  unsigned char	*buffs[2];
  unsigned char	fmt;
  int		val;

  fmt = proc->cmd[1];
  buffs[1] = proc->cmd + 2;
  buffs[0] = read[0];
  buffs[1] = get_args(app, proc, (fmt >> 6) & 3, buffs);
  buffs[0] = read[1];
  buffs[1] = get_args(app, proc, (fmt >> 6) & 3, buffs);
  val = char_to_int(read[0]) + char_to_int(read[1]);
  vm_cpyfrom(app, proc->pc + (val % IDX_MOD),
	     proc->registre[buffs[1][0]], 4);
  proc->carry = !char_to_int(proc->registre[buffs[1][0]]);
  buffs[1] = buffs[1] + 1;
  proc->pc = (proc->pc + buffs[1] - proc->cmd) % MEM_SIZE;
  return (0);
}

t_err		instruction_lld(t_application *app, t_process *proc)
{
  unsigned char	buff[4];
  unsigned char	*buffs[2];
  unsigned char	fmt;

  fmt = proc->cmd[1];
  buffs[1] = proc->cmd + 2;
  buffs[0] = buff;
  if (((fmt >> 6) & 3) != 3)
    buffs[1] = get_args(app, proc, (fmt >> 6) & 3, buffs);
  else
    {
      vm_cpyfrom(app, proc->pc + char_to_short(buffs[1]), buffs[0], 4);
      buffs[1] = buffs[1] + 2;
    }
  proc->carry = !char_to_int(buffs[0]);
  buffs[1] = set_args(app, proc, (fmt >> 4) & 3, buffs);
  proc->pc = (proc->pc + buffs[1] - proc->cmd) % MEM_SIZE;
  return (0);
}

t_err		instruction_lldi(t_application *app, t_process *proc)
{
  unsigned char	read[2][4];
  unsigned char	*buffs[2];
  unsigned char	fmt;
  int		val;

  fmt = proc->cmd[1];
  buffs[1] = proc->cmd + 2;
  buffs[0] = read[0];
  buffs[1] = get_args(app, proc, (fmt >> 6) & 3, buffs);
  buffs[0] = read[1];
  buffs[1] = get_args(app, proc, (fmt >> 6) & 3, buffs);
  val = char_to_int(read[0]) + char_to_int(read[1]);
  vm_cpyfrom(app, proc->pc + val,
	     proc->registre[buffs[1][0]], 4);
  proc->carry = !char_to_int(proc->registre[buffs[1][0]]);
  buffs[1] = buffs[1] + 1;
  proc->pc = (proc->pc + buffs[1] - proc->cmd) % MEM_SIZE;
  return (0);
}
