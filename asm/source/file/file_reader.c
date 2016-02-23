/*
** file_reader.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/file/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 22:17:17 2016 Benjamin Grange
** Last update Tue Feb 23 22:22:39 2016 Benjamin Grange
*/

#include "asm.h"

t_asm_file_reader	string_reader_create(t_asm_program_file *file,
					     const char *file_content)
{
  t_asm_file_reader	file_reader;

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
