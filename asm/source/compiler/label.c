/*
** label.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/compiler/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 03:31:44 2016 Benjamin Grange
** Last update Fri Mar 25 17:44:32 2016 Benjamin Grange
*/

#include "compiler.h"

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
      parser->label = label;
      /* FIXME */
      printf(YELLOW"Pushing label \"%s\" with value : %lu"WHITE"\n",
	     label->content,
	     addr);
      return (true);
    }
  my_puterror(RED"Double declaration of label \"");
  my_puterror(token->content_string);
  my_puterror("\" !\n"WHITE);
  return (false);
}
