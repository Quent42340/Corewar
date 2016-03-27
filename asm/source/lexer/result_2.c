/*
** result_2.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 17:54:48 2016 Benjamin Grange
** Last update Mon Mar 21 15:46:36 2016 Benjamin Grange
*/

#include "lexer.h"

t_result		get_null_result()
{
  t_result		result;

  result.type = RESULT_NULL;
  return (result);
}

t_result	create_result_from_string_token(t_file_reader *file,
						t_position pos)
{
  t_token	token;

  token = create_token(file, pos, TOKEN_TYPE_STRING);
  return (create_result_from_token(token));
}

t_result	create_result_from_comment_token(t_file_reader *file,
						 t_position pos)
{
  t_token	token;

  token = create_token(file, pos, TOKEN_TYPE_COMMENT);
  return (create_result_from_token(token));
}

t_result	create_result_from_whitespace_token(t_file_reader *file,
						    t_position pos)
{
  t_token	token;

  token = create_token(file, pos, TOKEN_TYPE_WHITESPACE);
  return (create_result_from_token(token));
}

t_result	create_result_from_eol_token(t_file_reader *file,
					     t_position pos)
{
  t_token	token;

  token = create_token(file, pos, TOKEN_TYPE_EOL);
  return (create_result_from_token(token));
}
