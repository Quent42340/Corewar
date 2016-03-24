/*
** program_config.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/compiler/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar 22 14:56:00 2016 Benjamin Grange
** Last update Thu Mar 24 15:01:25 2016 Benjamin Grange
*/

#include "parser.h"
#include "compiler.h"

t_parseres			set_program_config(t_parser *parser,
						   t_token *t, int i)
{
  if (i)
    {
      if (my_strlen(t->content_string) > PROG_NAME_LENGTH)
	return (get_se_rest(t, "Program name size is too big"));
      my_cpystr(parser->program.header.prog_name, t->content_string);
    }
  else
    {
      if (my_strlen(t->content_string) > COMMENT_LENGTH)
	return (get_se_rest(t, "Program comment size is too big"));
      my_cpystr(parser->program.header.comment, t->content_string);
    }
  return (get_instruction_result());
}
