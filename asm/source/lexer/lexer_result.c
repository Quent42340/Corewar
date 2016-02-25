/*
** lexer_result.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 11:50:36 2016 Benjamin Grange
** Last update Thu Feb 25 15:05:05 2016 Benjamin Grange
*/

#include "lexer.h"

t_result	create_result_from_syntax_error(t_position pos,
						char *error)
{
  t_result	res;

  res.type = RESULT_ERROR;
  res.syntax_error.position = pos;
  res.syntax_error.error = error;
  return (res);
}

t_result	create_result_from_token(t_token token)
{
  t_result	res;

  res.type = RESULT_TOKEN;
  res.token = token;
  return (res);
}

t_result	create_result_from_int_token(t_file_reader *file,
					     t_position pos,
					     int value)
{
  t_token	token;

  token = create_token(file, pos, TOKEN_TYPE_INTEGER);
  token.content.int_value = value;
  return (create_result_from_token(token));
}

t_result	create_result_from_op_token(t_file_reader *file,
					    t_position pos,
					    t_operator_enum operator)
{
  t_token	token;

  token = create_token(file, pos, TOKEN_TYPE_OPERATOR);
  token.content.operator = operator;
  return (create_result_from_token(token));
}
