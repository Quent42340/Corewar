/*
** parse_res.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar 22 12:57:05 2016 Benjamin Grange
** Last update Thu Mar 24 23:30:49 2016 Benjamin Grange
*/

#include "parser.h"

t_parseres			get_instruction_result(void)
{
  t_parseres			res;

  res.type = RESULT_PARSE_INSTRUCTION;
  return (res);
}

t_parseres			get_se_rest(t_token *t,
					    char *error)
{
  t_parseres			res;

  res.type = RESULT_PARSE_ERROR;
  res.syntax_error.position = t->begin;
  res.syntax_error.error = my_strdup(error);
  return (res);
}

t_parseres			get_se_res(t_token_list *t,
					   char *error)
{
  t_parseres			res;

  res.type = RESULT_PARSE_ERROR;
    res.syntax_error.position = t->token.begin;
  res.syntax_error.error = my_strdup(error);
  return (res);
}
