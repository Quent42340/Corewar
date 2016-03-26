/*
** lex_direct_label.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Mar  3 15:34:39 2016 Benjamin Grange
** Last update Mon Mar 21 15:40:22 2016 Benjamin Grange
*/

#include "lexer.h"

static int		is_label_char(char c)
{
  int			i;

  i = 0;
  while (LABEL_CHARS[i])
    {
      if (c == LABEL_CHARS[i])
	return (1);
      i++;
    }
  return (0);
}

static t_result	create_direct_label_result(t_file_reader *file,
					   t_position begin)
{
  t_token	token;

  token = create_token(file, begin, TOKEN_TYPE_DIRECT_LABEL);
  return (create_result_from_token(token));
}

t_result		lex_direct_label(t_file_reader *file)
{
  t_position		pos;
  t_position		pos2;
  t_position		prev;
  char			c;

  pos = file->cursor;
  c = string_reader_next(file);
  if (c == LABEL_CHAR)
    {
      pos2 = file->cursor;
      while (string_reader_has_more(file))
	{
	  prev = file->cursor;
	  c = string_reader_next(file);
	  if (!is_label_char(c))
	    {
	      file->cursor = prev;
	      break;
	    }
	}
      if (file->cursor.index > pos.index + 1)
	return (create_direct_label_result(file, pos2));
    }
  file->cursor = pos;
  return (get_null_result());
}
