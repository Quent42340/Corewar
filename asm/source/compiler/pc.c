/*
** pc.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/compiler/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 20:05:41 2016 Benjamin Grange
** Last update Sat Mar 26 17:00:04 2016 Benjamin Grange
*/

#include "compiler.h"

int				get_pc(t_program *program)
{
  int				size;
  t_operation			*op;

  op = program->op;
  size = 0;
  while (op && op->ended)
    {
      size += op->size;
      op = op->next;
    }
  return (size);
}
