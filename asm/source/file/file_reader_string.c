/*
** file_reader_string.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/file/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Feb 24 16:22:32 2016 Benjamin Grange
** Last update Wed Feb 24 16:24:46 2016 Benjamin Grange
*/

#include "asm.h"

t_bool			file_reader_read_string(t_file_reader *file_reader,
						char *string)
{
  t_position		checkpoint;
  char			c;

  checkpoint = file_reader->cursor;
  while (*string)
    {
      if (string_reader_has_more(file_reader) == FALSE)
	{
	  file_reader->cursor = checkpoint;
	  return (FALSE);
	}
      c = string_reader_next(file_reader);
      if (c != *string)
	{
	  file_reader->cursor = checkpoint;
	  return (FALSE);
	}
      string++;
    }
  return (TRUE);
}
