/*
** parse_label.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 21:44:30 2016 Benjamin Grange
** Last update Fri Mar 25 22:03:10 2016 Benjamin Grange
*/

#include "parser.h"
#include "compiler.h"

t_parseres		parse_label(t_parser *parser, t_token *token)
{
  if (!push_label(parser, token, get_pc(&parser->program)))
    {
      parser->program.is_valid = false;
      return (get_se_rest(token, "Label already declared."));
    }
  return (get_instruction_result());
}
