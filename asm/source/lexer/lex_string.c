/*
** lex_string.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 21:51:54 2016 Benjamin Grange
** Last update Tue Mar  1 03:35:24 2016 Benjamin Grange
*/

#include "lexer.h"

t_result		get_string_result(t_file_reader *reader,
					  t_position begin, char end)
{
  char			c;
  t_position		prev;

  while (string_reader_has_more(reader))
    {
      prev = reader->cursor;
      c = string_reader_next(reader);
      if (c == end)
	return (create_result_from_string_token(reader, begin));
      else if (c == '\n')
	return (create_result_from_se(prev,
				      "String didn't ended before EOL"));
    }
  return (create_result_from_se(reader->cursor, "String isn't closed"));
}

t_result		lex_string(t_file_reader *reader)
{
  t_position		begin;
  char			c;

  begin = reader->cursor;
  c = string_reader_next(reader);
  if (c != '\"' && c != '\'')
    {
      reader->cursor = begin;
      return (get_null_result());
    }
  return (get_string_result(reader, begin, c));
}
