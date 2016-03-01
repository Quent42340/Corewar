/*
** lex_identifiers.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar  1 01:54:14 2016 Benjamin Grange
** Last update Tue Mar  1 17:29:11 2016 Benjamin Grange
*/

#include "lexer.h"

t_bool			is_identifier(char c)
{
  if ((c >= 'a' && c <= 'z')
      || (c >= 'A' && c <= 'Z')
      || c == '.')
    return (TRUE);
  else
    return (FALSE);
}

t_result		determine_result_for_identif(t_file_reader *reader,
						     t_position begin)
{
  size_t		length;
  char			*string;
  t_result		result;

  length = reader->cursor.index - begin.index;
  if ((string = xmalloc(length + 1)) == NULL)
    {
      reader->cursor = begin;
      return (get_null_result());
    }
  my_memcpy(string, reader->file->content + begin.index, length);
  string[length] = '\0';
  result = lex_keyword(reader, begin, string);
  xfree(string);
  return (result);
}

t_result		lex_identifiers(t_file_reader *reader)
{
  t_position		begin;
  t_position		prev;
  t_result		result;
  char			c;

  begin = reader->cursor;
  c = string_reader_next(reader);
  if (!is_identifier(c))
    {
      reader->cursor = begin;
      return (get_null_result());
    }
  while (string_reader_has_more(reader))
    {
      prev = reader->cursor;
      c = string_reader_next(reader);
      if (!is_identifier(c))
	{
	  reader->cursor = prev;
	  break;
	}
    }
  result = determine_result_for_identif(reader, begin);
  return (result);
}
