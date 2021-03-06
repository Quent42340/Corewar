/*
** result.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 15:27:01 2016 Benjamin Grange
** Last update Tue Mar  1 03:05:12 2016 Benjamin Grange
*/

#include "lexer.h"

t_result	create_result_from_se(t_position pos, char *error)
{
  t_result	res;

  res.type = RESULT_ERROR;
  res.syntax_error.position = pos;
  res.syntax_error.error = my_strdup(error);
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

t_result	create_result_from_config_token(t_file_reader *file,
						t_position pos,
						t_config_enum config)
{
  t_token	token;

  token = create_token(file, pos, TOKEN_TYPE_CONFIG);
  token.content.config = config;
  return (create_result_from_token(token));
}
