/*
** parse_direct.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Mar 24 23:27:31 2016 Benjamin Grange
** Last update Fri Mar 25 15:30:11 2016 Benjamin Grange
*/

#include "compiler.h"
#include "parser.h"

static t_parseres		parse_direct_integer(t_token *token,
						     t_operation *op)
{
  add_param_operation(op, T_DIR, token->content.int_value);
  return (get_instruction_result());
}

static t_parseres		parse_direct_label(t_parser *parser,
						   t_token *token,
						   t_operation *op)
{
  t_label			*label;

  if (!token->content_string)
    return (get_se_rest(token, "Unexpected error"));
  label = get_label_by_name(parser, token->content_string);
  if (label == NULL)
    return (get_se_rest(token, "Label not defined"));
  add_param_operation(op, T_DIR, label->address);
  return (get_instruction_result());
}

t_parseres			parse_direct_value(t_parser *parser,
						   t_token *token,
						   t_operation *op)
{
  t_token			*value;

  if (has_next_token(parser))
    {
      value = get_next_token(parser);
      if (value->type == TOKEN_TYPE_INTEGER)
	return (parse_direct_integer(value, op));
      else if (value->type == TOKEN_TYPE_DIRECT_LABEL)
	return (parse_direct_label(parser, value, op));
      else
	return (get_se_rest(value,
			    "Expected a value/label after a direct char"));
    }
  else
    return (get_se_rest(token, "Expected a value/label after a direct char"));
}
