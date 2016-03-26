/*
** instruction.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/compiler/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 19:03:02 2016 Benjamin Grange
** Last update Sat Mar 26 19:52:00 2016 Benjamin Grange
*/

#include "compiler.h"
#include "parser.h"

static int			get_param_size(t_operation *op,
					       t_args_type param)
{
  if (param == T_REG)
    return (0);
  if (param == T_DIR)
    {
      if (is_param_index(op->op_num, op->nb_param))
	return (1);
      else
	return (3);
    }
  if (param == T_IND)
    return (2);
  return (0);
}

t_operation			*create_operation(t_parser *parser,
						  int op_num)
{
  t_operation			*op;

  op = xmalloc(sizeof(t_operation));
  if (!op)
    return (NULL);
  my_memset(op, 0, sizeof(t_operation));
  op->op_num = op_num;
  op->size = 1 + write_instruction_parameters(op_num);
  op->next = NULL;
  if (parser->program.op == NULL)
    parser->program.op = op;
  if (parser->program.last != NULL)
    parser->program.last->next = op;
  parser->program.last = op;
  return (op);
}

void				add_param_to_operation(t_operation *op,
						       t_args_type type,
						       unsigned value)
{
  op->param_type += (type << (2 * (3 - op->nb_param % 4)));
  op->param_size[op->nb_param] = get_param_size(op, type);
  if (op->param_size[op->nb_param] == 0)
    {
      op->param_content[op->nb_param].reg = value;
      op->size += 1;
    }
  else if (op->param_size[op->nb_param] == 1)
    {
      op->param_content[op->nb_param].index = value;
      op->size += IND_SIZE;
    }
  else if (op->param_size[op->nb_param] == 2)
    {
      op->param_content[op->nb_param].indirect = value;
      op->size += IND_SIZE;
    }
  else if (op->param_size[op->nb_param] == 3)
    {
      op->param_content[op->nb_param].direct = value;
      op->size += DIR_SIZE;
    }
  op->nb_param += 1;
}
