/*
** free_parser.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Mar 27 01:33:11 2016 Benjamin Grange
** Last update Sun Mar 27 01:53:47 2016 Benjamin Grange
*/

#include "parser.h"

void				free_label(t_parser *parser)
{
  t_label			*label;
  void				*tmp;
  t_labelr			*labelr;

  label = parser->label;
  while (label)
    {
      tmp = label->next;
      if (label->name)
	xfree(label->name);
      xfree(label);
      label = tmp;
    }
  labelr = parser->labelr;
  while (labelr)
    {
      tmp = labelr->next;
      xfree(labelr);
      labelr = tmp;
    }
}
