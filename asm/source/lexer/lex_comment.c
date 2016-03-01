/*
** lex_comment.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar  1 10:29:43 2016 Benjamin Grange
** Last update Tue Mar  1 12:54:47 2016 Benjamin Grange
*/

#include "lexer.h"

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
