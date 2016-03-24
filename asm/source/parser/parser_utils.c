/*
** parser_utils.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Mon Mar 21 17:44:13 2016 Benjamin Grange
** Last update Tue Mar 22 22:42:31 2016 Benjamin Grange
*/

#include "parser.h"

t_bool				has_next_token(t_parser *parser)
{
  return (!!parser->tkn);
}

t_token				*get_next_token(t_parser *parser)
{
  t_token_list			*token_l;

  token_l = parser->tkn;
  if (token_l != NULL)
    {
      parser->tkn = parser->tkn->next;
      return (&token_l->token);
    }
  return (NULL);
}
