/*
** result_2.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 17:54:48 2016 Benjamin Grange
** Last update Tue Mar  1 11:01:31 2016 Benjamin Grange
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
