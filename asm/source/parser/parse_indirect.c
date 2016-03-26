/*
** parse_indirect.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 20:00:29 2016 Benjamin Grange
** Last update Sat Mar 26 16:51:20 2016 Benjamin Grange
*/

#include "compiler.h"
#include "parser.h"

static t_parseres		parse_indirect_integer(t_token *token,
						       t_operation *op)
{
  add_param_to_operation(op, T_IND, token->content.int_value);
  return (get_instruction_result());
}

static t_parseres		parse_indirect_label(t_parser *parser,
						     t_token *token,
						     t_operation *op)
{
  add_param_to_operation(op, T_IND, 0);
  if (push_label_request(parser, token,
			 op->param_size[op->nb_param - 1],
			 &op->param_content[op->nb_param - 1]))
    return (get_instruction_result());
  else
    return (get_se_rest(token, "Failed to push label."));
}

t_parseres			parse_indirect_value(t_parser *parser,
						     t_token *token,
						     t_operation *op)
{
  if (token->type == TOKEN_TYPE_INTEGER)
    return (parse_indirect_integer(token, op));
  else if (token->type == TOKEN_TYPE_DIRECT_LABEL)
    return (parse_indirect_label(parser, token, op));
  else
    return (get_se_rest(token, "Unexpected error on indirect values"));
}
