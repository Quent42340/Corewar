/*
** file_reader.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/file/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 22:17:17 2016 Benjamin Grange
** Last update Thu Feb 25 18:37:54 2016 Benjamin Grange
*/

#include "asm.h"

char			string_reader_next(t_file_reader *reader)
{
  char			c;

  c = reader->file->content[reader->cursor.index++];
  if (c == '\n')
    {
      reader->cursor.line++;
      reader->cursor.column = 0;
    }
  else
    reader->cursor.column++;
  return (c);
}

t_bool			string_reader_has_more(t_file_reader *reader)
{
  return (reader->cursor.index < reader->file->file_size);
}

t_file_reader		string_reader_create(t_program_file *file,
					     const char *file_content)
{
  t_file_reader	file_reader;

  if (file_content != NULL)
    {
      file_reader.cursor.index = 0;
      file_reader.cursor.line = 0;
      file_reader.cursor.column = 0;
      file_reader.cursor.file = file;
      file_reader.file = file;
    }
  return (file_reader);
}
