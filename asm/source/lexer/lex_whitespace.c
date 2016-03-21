/*
** lex_whitespace.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Mon Mar 21 14:31:36 2016 Benjamin Grange
** Last update Mon Mar 21 15:44:57 2016 Benjamin Grange
*/

#include "lexer.h"

t_result		lex_whitespace(t_file_reader *reader)
{
  t_position		pos;
  t_position		prev;
  char			c;

  pos = reader->cursor;
  c = string_reader_next(reader);
  if (c == ' ' || c == '\t')
    {
      while (string_reader_has_more(reader))
	{
	  prev = reader->cursor;
	  c = string_reader_next(reader);
	  if (c != ' ' && c != '\t')
	    {
	      reader->cursor = prev;
	      return (create_result_from_whitespace_token(reader, pos));
	    }
	}
    }
  reader->cursor = pos;
  return (get_null_result());
}
