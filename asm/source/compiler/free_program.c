/*
** free_program.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/compiler/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Mar 27 01:37:40 2016 Benjamin Grange
** Last update Sun Mar 27 01:38:58 2016 Benjamin Grange
*/

#include "compiler.h"

void				free_program(t_program *prog)
{
  t_operation			*op;
  t_operation			*tmp;

  op = prog->op;
  while (op)
    {
      tmp = op->next;
      xfree(op);
      op = tmp;
    }
}
