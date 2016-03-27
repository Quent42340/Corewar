/*
** parse_label.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 00:12:27 2016 Benjamin Grange
** Last update Fri Mar 25 03:32:12 2016 Benjamin Grange
*/

#include "compiler.h"
#include "parser.h"

void				delete_label(t_parser *parser,
					     t_token_list **token,
					     t_token_list *prev)
{
  t_token_list			*tmp;

  tmp = (*token)->next;
  if (prev != NULL)
    prev->next = (*token)->next;
  else
    parser->tokenlist = (*token)->next;
  (*token)->next = NULL;
  free_token_list(*token);
  *token = tmp;
}

t_bool				pre_compile_label_declaration(t_parser *parser)
{
  t_token_list			*token;
  t_token_list			*prev;
  size_t			address;

  address = 0;
  prev = NULL;
  token = parser->tokenlist;
  while (token)
    {
      if (token->token.type == TOKEN_TYPE_LABEL)
	{
	  if (!push_label(parser, &token->token, address))
	    {
	      parser->program.is_valid = false;
	      return (false);
	    }
	  delete_label(parser, &token, prev);
	  continue;
	}
      else
	add_address(token, &address);
      prev = token;
      token = token->next;
    }
  return (true);
}
