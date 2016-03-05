/*
** lex_label.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Mar  2 00:52:54 2016 Benjamin Grange
** Last update Thu Mar  3 15:35:20 2016 Benjamin Grange
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

static t_result	create_result_from_label_token(t_file_reader *file,
					       t_position pos,
					       char *label)
{
  t_token	token;

  token = create_token(file, pos, TOKEN_TYPE_LABEL);
  token.content.string_value = my_strdup(label);
  return (create_result_from_token(token));
}

static t_result		determine_result_for_label(t_file_reader *reader,
						   t_position begin,
						   t_position save)
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
  result = create_result_from_label_token(reader, begin, string);
  xfree(string);
  reader->cursor = save;
  return (result);
}

t_result		lex_label(t_file_reader *reader)
{
  t_position		pos;
  t_position		prev;
  t_position		save;
  char			c;

  pos = reader->cursor;
  while (string_reader_has_more(reader))
    {
      prev = reader->cursor;
      c = string_reader_next(reader);
      if (c == LABEL_CHAR && prev.index != pos.index)
	{
	  save = reader->cursor;
	  reader->cursor = prev;
	  return (determine_result_for_label(reader, pos, save));
	}
      if (!is_label_char(c))
	{
	  reader->cursor = pos;
	  return (get_null_result());
	}
    }
  reader->cursor = pos;
  return (get_null_result());
}
