/*
** parse_label.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 00:12:27 2016 Benjamin Grange
** Last update Fri Mar 25 03:24:27 2016 Benjamin Grange
*/

#include "compiler.h"
#include "parser.h"

t_label				*get_label_by_name(t_parser *parser,
						   char *name)
{
  t_label			*label;

  label = parser->label;
  while (label)
    {
      if (my_strcmp(name, label->content))
	return (label);
      label = label->next;
    }
  return (NULL);
}

t_bool				push_label(t_parser *parser,
					   t_token *token,
					   size_t addr)
{
  t_label			*label;

  label = get_label_by_name(parser, token->content_string);
  if (label == NULL)
    {
      label = xmalloc(sizeof(t_label));
      if (!label)
	return (false);
      label->content = my_strdup(token->content_string);
      if (!label->content)
	return (false);
      label->address = addr;
      label->next = parser->label;
      parser->label = label; /* FIXME */
      my_putstr(YELLOW"Pushing label \"");
      my_putstr(label->content);
      my_putstr("\" with value : ");
      my_putnbr_error(addr);
      my_putchar('\n');
      my_putstr(WHITE);
      return (true);
    }
  my_puterror(RED"Double declaration of label \"");
  my_puterror(token->content_string);
  my_puterror("\" !\n"WHITE);
  return (false);
}

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
