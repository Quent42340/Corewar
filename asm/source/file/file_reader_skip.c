/*
** file_reader_skip.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/file/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Feb 24 12:50:04 2016 Benjamin Grange
** Last update Wed Feb 24 13:13:24 2016 Benjamin Grange
*/

#include "asm.h"

int			string_reader_skip(t_file_reader *file_reader,
					   char *to_skip)
{
  char			c;
  int			count;
  t_position		checkpoint;

  while (string_reader_has_more(file_reader))
    {
      checkpoint = file_reader->cursor;
      c = string_reader_next(file_reader);
      if (my_strchr(to_skip, c) == NULL)
	{
	  file_reader->cursor = checkpoint;
	  break;
	}
      count++;
    }
  return (count);
}

int			string_reader_skip_whitespace(t_file_reader *reader)
{
  return (string_reader_skip(reader, " \t\n"));
}
