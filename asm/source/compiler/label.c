/*
** label.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/compiler/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 03:31:44 2016 Benjamin Grange
** Last update Sun Mar 27 01:53:55 2016 Benjamin Grange
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
      if (my_strcmp(name, label->name))
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
      my_memset(label, 0, sizeof(t_label));
      label->name = my_strdup(token->content_string);
      if (!label->name)
	return (false);
      label->address = addr;
      label->next = parser->label;
      parser->label = label;
      return (true);
    }
  return (false);
}

t_bool				push_label_request(t_parser *parser,
						   t_token *t, int type,
						   t_content *content)
{
  t_labelr			*labelr;

  labelr = xmalloc(sizeof(t_labelr));
  if (!labelr)
    return (false);
  my_memset(labelr, 0, sizeof(t_labelr));
  labelr->token = t;
  labelr->cur_pc = get_pc(&parser->program);
  labelr->type = type;
  labelr->content = content;
  if (parser->labelr)
      labelr->next = parser->labelr;
    parser->labelr = labelr;
  return (true);
}

void				pop_label_request(t_parser *parser)
{
  t_label			*label;
  t_parseres			res;
  t_labelr			*labelr;

  labelr = parser->labelr;
  while (labelr)
    {
      label = get_label_by_name(parser, labelr->token->content_string);
      if (!label)
	{
	  res = get_se_rest(labelr->token, "Use of undefined label");
	  parser->program.is_valid = false;
	  print_syntax_error(parser->reader, &res.syntax_error, NULL);
	  return ;
	}
      if (labelr->type == 1)
	labelr->content->index = (short)(label->address - labelr->cur_pc);
      else if (labelr->type == 2)
	labelr->content->indirect = (short)(label->address - labelr->cur_pc);
      else
	labelr->content->direct = (int)(label->address - labelr->cur_pc);
      labelr = labelr->next;
    }
}
