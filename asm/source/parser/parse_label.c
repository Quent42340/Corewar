/*
** parse_label.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 21:44:30 2016 Benjamin Grange
** Last update Sun Mar 27 01:01:17 2016 Benjamin Grange
*/

#include "parser.h"
#include "compiler.h"

t_parseres		parse_label(t_parser *parser, t_token *token)
{
  t_token		*t2;

  if (!push_label(parser, token, get_pc(&parser->program)))
    {
      parser->program.is_valid = false;
      return (get_se_rest(token, "Label already declared."));
    }
  if (has_next_token(parser))
    {
      t2 = get_next_token(parser);
      if (t2->type != TOKEN_TYPE_WHITESPACE && t2->type != TOKEN_TYPE_EOL)
	return (get_se_rest(t2, "Label must be followed by a whitespace"));
    }
  return (get_instruction_result());
}
