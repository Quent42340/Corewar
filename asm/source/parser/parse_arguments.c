/*
** parse_arguments.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Mar 23 23:59:04 2016 Benjamin Grange
** Last update Fri Mar 25 15:28:44 2016 Benjamin Grange
*/

#include "parser.h"

t_parseres			parse_arguments(t_parser *parser,
						t_token *token,
						t_operation *op,
						t_args_type t)
{
  if ((t & T_REG) && token->type == TOKEN_TYPE_REGISTER)
    return (parse_register(token, op));
  else if ((t & T_DIR) && (token->type == TOKEN_TYPE_OPERATOR
	    && token->content.operator == OPERATOR_DIRECT))
    return (parse_direct_value(parser, token, op));
  else if ((t & T_IND) && (token->type == TOKEN_TYPE_INTEGER
	    || token->type == TOKEN_TYPE_DIRECT_LABEL))
    {

    }
  else
    return (get_se_rest(token, "Bad parameter type"));
  return (get_instruction_result());
}
