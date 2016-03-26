/*
** parse_instruction.c for corewar in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Mar 23 16:56:14 2016 Benjamin Grange
** Last update Fri Mar 25 20:04:56 2016 Benjamin Grange
*/

#include "parser.h"
#include "compiler.h"

static t_parseres	not_enough_arguments(t_token *token)
{
  return (get_se_rest(token, "Not enough parameters to instruction"));
}

static t_parseres	parse_comma(t_parser *parser, t_token *token,
				    int i, t_op *op)
{
  t_token		*comma;

  if (i < op->nbr_args - 1)
    {
      parse_whitespace(parser);
      if (!has_next_token(parser))
	return (not_enough_arguments(token));
      comma = get_next_token(parser);
      if (comma->type != TOKEN_TYPE_OPERATOR
	  || comma->content.operator != OPERATOR_COMMA)
	return (get_se_rest(comma, "Expected a comma after a paramter"));
    }
  return (get_instruction_result());
}

t_parseres		parse_instruction(t_parser *parser, t_token *token)
{
  t_operation		*oper;
  t_parseres		res;
  t_op			op;
  int			i;

  i = 0;
  op = op_tab[token->content.instruction - 1];
  oper = create_operation(parser, op.code);
  if (!oper || parse_whitespace(parser))
    return (not_enough_arguments(token));
  while (i < op.nbr_args)
    {
      parse_whitespace(parser);
      if (!has_next_token(parser))
	return (not_enough_arguments(token));
      res = parse_arguments(parser, get_next_token(parser), oper, op.type[i]);
      if (res.type == RESULT_PARSE_ERROR)
	return (res);
      res = parse_comma(parser, token, i, &op);
      if (res.type == RESULT_PARSE_ERROR)
	return (res);
      i++;
    }
  return (get_instruction_result());
}
