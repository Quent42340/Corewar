/*
** parse_whitespace.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar 22 15:27:33 2016 Benjamin Grange
** Last update Sun Mar 27 15:56:35 2016 Benjamin Grange
*/

#include "parser.h"

t_parseres			get_whitespace_error(t_token *tkn)
{
  return (get_se_rest(tkn, "Missing next token"));
}

t_bool				parse_whitespace(t_parser *parser)
{
  t_bool			b;

  b = true;
  while (has_next_token(parser)
	 && parser->tkn->token.type == TOKEN_TYPE_WHITESPACE)
    {
      get_next_token(parser);
      b = false;
    }
  return (b);
}
