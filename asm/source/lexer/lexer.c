/*
** lexer.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:25:28 2016 Benjamin Grange
** Last update Thu Feb 25 15:06:13 2016 Benjamin Grange
*/

#include "asm.h"
#include "lexer.h"

t_result		lex_token(t_file_reader *file)
{
  t_result		r;

  (void)file;
  return (r);
}

t_token_list		*lexer(t_file_reader *file)
{
  t_token_list		*list;
  t_result		result;

  list = NULL;
  while (string_reader_has_more(file))
    {
      string_reader_skip_whitespace(file);
      if (!string_reader_has_more(file))
	break;
      result = lex_token(file);
      if (result.type == RESULT_ERROR)
	{
	  my_putstr(result.syntax_error.error);
	  return (NULL);
	}
    }
  return (list);
}
