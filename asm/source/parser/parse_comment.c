/*
** parse_whitespace.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Mon Mar 21 16:50:31 2016 Benjamin Grange
** Last update Tue Mar 22 17:24:53 2016 Benjamin Grange
*/

#include "parser.h"

void				delete_all_comments(t_token_list **list)
{
  t_token_list			*elem;
  t_token_list			*prev;
  t_token_list			*tmp;

  elem = *list;
  prev = NULL;
  while (elem != NULL)
    {
      if (elem->token.type == TOKEN_TYPE_COMMENT)
	{
	  tmp = elem->next;
	  if (prev != NULL)
	    prev->next = elem->next;
	  else
	    *list = elem->next;
	  elem->next = NULL;
	  free_token_list(elem);
	  elem = tmp;
	  continue;
	}
      prev = elem;
      elem = elem->next;
    }
}
