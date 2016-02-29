/*
** lexer.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:25:28 2016 Benjamin Grange
** Last update Thu Feb 25 20:09:55 2016 Benjamin Grange
*/

#include "asm.h"
#include "lexer.h"

t_file_reader		generate_file_reader(t_program_file *file)
{
  t_file_reader		file_reader;

  file_reader.cursor.file = file;
  file_reader.cursor.index = 0;
  file_reader.cursor.line = 0;
  file_reader.cursor.column = 0;
  file_reader.file = file;
  return (file_reader);
}

void			*print_unexpected_char_error(t_file_reader *reader)
{
  t_result		result;
  char			*error;

  error = my_strdup("Unexpected char ' '");
  if (error == NULL)
    return (NULL);
  error[17] = reader->file->content[reader->cursor.index];
  result.syntax_error.position = reader->cursor;
  result.syntax_error.error = error;
  print_syntax_error(reader, &result);
  xfree(error);
  return (NULL);
}

t_token_list		*lexer(t_program_file *file)
{
  t_token_list		*list;
  t_result		result;
  t_file_reader		file_reader;

  list = NULL;
  if (file == NULL)
    return (NULL);
  file_reader = generate_file_reader(file);
  while (string_reader_has_more(&file_reader))
    {
      string_reader_skip_whitespace(&file_reader);
      if (!string_reader_has_more(&file_reader))
	break;
      result = lex_token(&file_reader);
      if (result.type == RESULT_ERROR)
	return (print_syntax_error(&file_reader, &result));
      else if (result.type == RESULT_NULL)
	return (print_unexpected_char_error(&file_reader));
    }
  return (list);
}
