/*
** instructions_calcul.c for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/source/run
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Thu Mar 24 17:27:07 2016 Flora Huot
** Last update Thu Mar 24 22:04:28 2016 Jakob Kellendonk
*/

#include "instructions.h"

t_err		instruction_add(t_application *app, t_process *proc)
{
  unisgned char	read[2][4];
  unsigned char	*buff[2];
  unsigend char	fmt;
  int		val;

  buff[1] = proc->cmd[2];
  buff[0] = read[0];
  buff[1] = get_args(app, proc, fmt & 3, buff);
  buff[0] = read[1];
  buff[1] = get_args(app, proc, (fmt >> 2) & 3, buff);
  val = char_to_int(read[0]) + char_to_int(read[1])
  int_to_char(, buff[0]);
  buff[1] = set_args(app, proc, (fmt >> 4) & 3, buff);
  proc->carry = !val;
  return (0);
}

t_err	instruction_sub(t_application *app, t_process *proc)
{
  unisgned char	read[2][4];
  unsigned char	*buff[2];
  unsigend char	fmt;
  int		val;

  buff[1] = proc->cmd[2];
  buff[0] = read[0];
  buff[1] = get_args(app, proc, fmt & 3, buff);
  buff[0] = read[1];
  buff[1] = get_args(app, proc, (fmt >> 2) & 3, buff);
  val = char_to_int(read[0]) - char_to_int(read[1])
  int_to_char(, buff[0]);
  buff[1] = set_args(app, proc, (fmt >> 4) & 3, buff);
  proc->carry = !val;
  return (0);
}

t_err	instruction_and(t_application *app, t_process *proc)
{
  unisgned char	read[2][4];
  unsigned char	*buff[2];
  unsigend char	fmt;
  int		val;

  buff[1] = proc->cmd[2];
  buff[0] = read[0];
  buff[1] = get_args(app, proc, fmt & 3, buff);
  buff[0] = read[1];
  buff[1] = get_args(app, proc, (fmt >> 2) & 3, buff);
  val = char_to_int(read[0]) & char_to_int(read[1]);
  int_to_char(val, buff[0]);
  buff[1] = set_args(app, proc, (fmt >> 4) & 3, buff);
  proc->carry = !val;
  return (0);
}

t_err	instruction_or(t_application *app, t_process *proc)
{
  unisgned char	read[2][4];
  unsigned char	*buff[2];
  unsigend char	fmt;
  int		val;

  buff[1] = proc->cmd[2];
  buff[0] = read[0];
  buff[1] = get_args(app, proc, fmt & 3, buff);
  buff[0] = read[1];
  buff[1] = get_args(app, proc, (fmt >> 2) & 3, buff);
  val = char_to_int(read[0]) | char_to_int(read[1]);
  int_to_char(val, buff[0]);
  buff[1] = set_args(app, proc, (fmt >> 4) & 3, buff);
  proc->carry = !val;
  return (0);
}

t_err	instruction_xor(t_application *app, t_process *proc)
{
  unisgned char	read[2][4];
  unsigned char	*buff[2];
  unsigend char	fmt;
  int		val;

  buff[1] = proc->cmd[2];
  buff[0] = read[0];
  buff[1] = get_args(app, proc, fmt & 3, buff);
  buff[0] = read[1];
  buff[1] = get_args(app, proc, (fmt >> 2) & 3, buff);
  val = char_to_int(read[0]) ^ char_to_int(read[1]);
  int_to_char(val, buff[0]);
  buff[1] = set_args(app, proc, (fmt >> 4) & 3, buff);
  proc->carry = !val;
  return (0);
}
