/*
** lexer.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:25:28 2016 Benjamin Grange
** Last update Wed Mar 23 00:11:17 2016 Benjamin Grange
*/

#include "asm.h"
#include "lexer.h"
#include "file_reader.h"

t_token_list		*lexer(t_program_file *file, t_bool *lexer_result)
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
      result = lex_token(&file_reader);
      if (result.type == RESULT_ERROR)
	return (print_syntax_error(&file_reader, &result.syntax_error, list));
      else if (result.type == RESULT_NULL)
	return (print_unexpected_char_error(&file_reader, list));
      else if (result.type == RESULT_TOKEN
	       && add_token_to_list(&list, result.token))
        return (print_error_n("Error while adding token to list.\n"));
    }
  *lexer_result = true;
  return (list);
}
