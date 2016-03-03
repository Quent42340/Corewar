/*
** lex_comment.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar  1 10:29:43 2016 Benjamin Grange
** Last update Thu Mar  3 14:44:34 2016 Benjamin Grange
*/

#include "lexer.h"

t_result		lex_multiline_comment(t_file_reader *reader)
{
  t_position		pos;
  char			c;
  char			c2;

  pos = reader->cursor;
  c = string_reader_next(reader);
  if (!string_reader_has_more(reader))
    return (get_null_result());
  c2 = string_reader_next(reader);
  if (c == '/' && c2 == '*')
    {
      while (string_reader_has_more(reader))
	{
	  c = c2;
	  c2 = string_reader_next(reader);
	  if (c == '*' && c2 == '/')
	    return (create_result_from_comment_token(reader, pos));
	}
      return (create_result_from_se(reader->cursor, "Unterminated comment"));
    }
  reader->cursor = pos;
  return (get_null_result());
}

t_result		lex_comment(t_file_reader *reader)
{
  t_position		pos;
  t_position		prev;
  char			c;

  pos = reader->cursor;
  c = string_reader_next(reader);
  if (c == COMMENT_CHAR)
    {
      while (string_reader_has_more(reader))
	{
	  prev = reader->cursor;
	  c = string_reader_next(reader);
	  if (c == '\n')
	    {
	      reader->cursor = prev;
	      return (create_result_from_comment_token(reader, pos));
	    }
	}
    }
  reader->cursor = pos;
  return (get_null_result());
}
