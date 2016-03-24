/*
** parse_direct.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Mar 24 23:27:31 2016 Benjamin Grange
** Last update Thu Mar 24 23:52:22 2016 Benjamin Grange
*/

#include "parser.h"

t_parseres			parse_direct_value(t_parser *parser,
						   t_token *token,
						   t_operation *op)
{
  t_token			*value;

  if (has_next_token(parser))
    {
      value = get_next_token(parser);
      if (value->type == TOKEN_TYPE_INTEGER)
	{

	}
      else if (value->type == TOKEN_TYPE_DIRECT_LABEL)
	{

	}
      else
	get_se_res(value, "Expected a value/label after a direct char");
    }
  else
    return (get_se_res(token, "Expected a value/label after a direct char"));
}
