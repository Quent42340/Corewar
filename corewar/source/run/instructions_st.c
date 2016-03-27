/*
** instructions_st.c for  in corewar/source/run
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Thu Mar 24 17:30:13 2016 Flora Huot
** Last update Mon Mar 28 01:51:50 2016 Jakob Kellendonk
*/

#include "vm_copy.h"

t_err		instruction_st(t_application *app, t_process **proc)
{
  unsigned char	buff[4];
  unsigned char	*buffs[2];
  unsigned char	fmt;

  fmt = (*proc)->cmd[1];
  buffs[1] = (*proc)->cmd + 2;
  buffs[0] = buff;
  buffs[1] = get_args(app, *proc, (fmt >> 6) & 3, buffs);
  buffs[1] = set_args(app, *proc, (fmt >> 4) & 3, buffs);
  (*proc)->pc = (*proc)->pc + buffs[1] - (*proc)->cmd;
  return (0);
}

t_err	instruction_sti(t_application *app, t_process **proc)
{
  unsigned char	read[3][4];
  unsigned char	*buffs[2];
  unsigned char	fmt;
  int		val;

  fmt = (*proc)->cmd[1];
  buffs[1] = (*proc)->cmd + 2;
  buffs[0] = read[0];
  buffs[1] = get_args(app, *proc, (fmt >> 6) & 3, buffs);
  buffs[0] = read[1];
  val = get_args_index(app, *proc, (fmt >> 4) & 3, buffs);
  buffs[0] = read[2];
  val = val + get_args_index(app, *proc, (fmt >> 2) & 3, buffs);
  vm_cpyto(app, (*proc)->pc + val % IDX_MOD, read[0], 4);
  if (app->st_callback)
    app->st_callback(app, (*proc)->parent, (*proc)->pc
		     + (val % IDX_MOD), 4);
  (*proc)->pc = (*proc)->pc + buffs[1] - (*proc)->cmd;
  return (0);
}
