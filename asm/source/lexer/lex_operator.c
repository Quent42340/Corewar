/*
** lex_operator.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar  1 23:07:42 2016 Benjamin Grange
** Last update Wed Mar  2 15:49:28 2016 Benjamin Grange
*/

#include "lexer.h"
#include "operator.h"

t_result		lex_operator(t_file_reader *reader)
{
  t_position		pos;
  char			c;

  pos = reader->cursor;
  c = string_reader_next(reader);
  if (c == SEPARATOR_CHAR)
    return (create_result_from_op_token(reader, pos, OPERATOR_COMMA));
  else if (c == '+')
    return (create_result_from_op_token(reader, pos, OPERATOR_PLUS));
  else if (c == '-')
    return (create_result_from_op_token(reader, pos, OPERATOR_MINUS));
  else if (c == DIRECT_CHAR)
    return (create_result_from_op_token(reader, pos, OPERATOR_DIRECT));
  reader->cursor = pos;
  return (get_null_result());
}
