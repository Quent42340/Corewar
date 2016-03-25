/*
** instructions_calcul.c for  corewar int corewar/source/run
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Thu Mar 24 17:27:07 2016 Flora Huot
** Last update Fri Mar 25 18:07:18 2016 Jakob Kellendonk
*/

#include "instructions.h"
#include "vm_copy.h"
#include "my_mem.h"

t_err		instruction_add(t_application *app, t_process *proc)
{
  unsigned char	read[2][4];
  unsigned char	*buff[2];
  unsigned char	fmt;
  int		val;

  fmt = proc->cmd[1];
  buff[1] = proc->cmd + 2;
  buff[0] = read[0];
  buff[1] = get_args(app, proc, (fmt >> 6) & 3, buff);
  buff[0] = read[1];
  buff[1] = get_args(app, proc, (fmt >> 4) & 3, buff);
  val = char_to_int(read[0]) + char_to_int(read[1]);
  int_to_char(val, buff[0]);
  buff[1] = set_args(app, proc, (fmt >> 2) & 3, buff);
  proc->carry = !val;
  proc->pc = (proc->pc + buff[1] - proc->cmd) % MEM_SIZE;
  return (0);
}

t_err	instruction_sub(t_application *app, t_process *proc)
{
  unsigned char	read[2][4];
  unsigned char	*buff[2];
  unsigned char	fmt;
  int		val;

  fmt = proc->cmd[1];
  buff[1] = proc->cmd + 2;
  buff[0] = read[0];
  buff[1] = get_args(app, proc, (fmt >> 6) & 3, buff);
  buff[0] = read[1];
  buff[1] = get_args(app, proc, (fmt >> 4) & 3, buff);
  val = char_to_int(read[0]) - char_to_int(read[1]);
  int_to_char(val, buff[0]);
  buff[1] = set_args(app, proc, (fmt >> 2) & 3, buff);
  proc->carry = !val;
  proc->pc = (proc->pc + buff[1] - proc->cmd) % MEM_SIZE;
  return (0);
}

t_err	instruction_and(t_application *app, t_process *proc)
{
  unsigned char	read[2][4];
  unsigned char	*buff[2];
  unsigned char	fmt;
  int		val;

  fmt = proc->cmd[1];
  buff[1] = proc->cmd + 2;
  buff[0] = read[0];
  buff[1] = get_args(app, proc, (fmt >> 6) & 3, buff);
  buff[0] = read[1];
  buff[1] = get_args(app, proc, (fmt >> 4) & 3, buff);
  val = char_to_int(read[0]) & char_to_int(read[1]);
  int_to_char(val, buff[0]);
  buff[1] = set_args(app, proc, (fmt >> 2) & 3, buff);
  proc->carry = !val;
  proc->pc = (proc->pc + buff[1] - proc->cmd) % MEM_SIZE;
  return (0);
}

t_err	instruction_or(t_application *app, t_process *proc)
{
  unsigned char	read[2][4];
  unsigned char	*buff[2];
  unsigned char	fmt;
  int		val;

  fmt = proc->cmd[1];
  buff[1] = proc->cmd + 2;
  buff[0] = read[0];
  buff[1] = get_args(app, proc, (fmt >> 6) & 3, buff);
  buff[0] = read[1];
  buff[1] = get_args(app, proc, (fmt >> 4) & 3, buff);
  val = char_to_int(read[0]) | char_to_int(read[1]);
  int_to_char(val, buff[0]);
  buff[1] = set_args(app, proc, (fmt >> 4) & 3, buff);
  proc->carry = !val;
  proc->pc = (proc->pc + buff[1] - proc->cmd) % MEM_SIZE;
  return (0);
}

t_err	instruction_xor(t_application *app, t_process *proc)
{
  unsigned char	read[2][4];
  unsigned char	*buff[2];
  unsigned char	fmt;
  int		val;

  fmt = proc->cmd[1];
  buff[1] = proc->cmd + 2;
  buff[0] = read[0];
  buff[1] = get_args(app, proc, (fmt >> 6) & 3, buff);
  buff[0] = read[1];
  buff[1] = get_args(app, proc, (fmt >> 4) & 3, buff);
  val = char_to_int(read[0]) ^ char_to_int(read[1]);
  int_to_char(val, buff[0]);
  buff[1] = set_args(app, proc, (fmt >> 2) & 3, buff);
  proc->carry = !val;
  proc->pc = proc->pc + buff[1] - proc->cmd;
  return (0);
}
