/*
** token_list.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Mon Feb 29 23:44:30 2016 Benjamin Grange
** Last update Tue Mar  1 03:11:00 2016 Benjamin Grange
*/

#include "asm.h"
#include "lexer.h"

t_token_list		*get_last_token(t_token_list *tokenlist)
{
  if (tokenlist == NULL)
    return (NULL);
  while (tokenlist->next != NULL)
    tokenlist = tokenlist->next;
  return (tokenlist);
}

int			add_token_to_list(t_token_list **tokenlist,
					  t_token t)
{
  t_token_list		*new_token;
  t_token_list		*last_token;

  last_token = get_last_token(*tokenlist);
  new_token = xmalloc(sizeof(t_token_list));
  if (new_token == NULL)
    return (-1);
  new_token->token = t;
  new_token->next = NULL;
  if (last_token != NULL)
    last_token->next = new_token;
  else
    *tokenlist = new_token;
  return (0);
}

void			free_token_list(t_token_list *list)
{
  t_token_list		*tmp;

  while (list != NULL)
    {
      tmp = list->next;
      if (list->token.content_string != NULL)
	xfree(list->token.content_string);
      xfree(list);
      list = tmp;
    }
}
