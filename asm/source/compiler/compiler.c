/*
** compiler.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/compiler/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Mar 24 22:45:10 2016 Benjamin Grange
** Last update Fri Mar 25 18:00:30 2016 Benjamin Grange
*/

#include "compiler.h"

void				add_operation(t_parser *parser,
					      t_operation *src)
{
  t_operation			*op;

  op = xmalloc(sizeof(t_operation));
  my_memcpy(op, src, sizeof(t_operation));
  if (op != NULL)
    {
      if (parser->program.last != NULL)
	parser->program.last->next = op;
      else
	parser->program.op = op;
      parser->program.last = op;
    }
}

void				add_param_operation(t_operation *op,
						    int type,
						    int value)
{
  if (op->nb_params < MAX_ARGS_NUMBER)
    {
      op->params_type[op->nb_params] = type;
      op->params_value[op->nb_params] = value;
      op->nb_params++;
    }
}
