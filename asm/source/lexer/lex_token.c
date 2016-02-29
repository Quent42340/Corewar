/*
** lex_token.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 15:12:25 2016 Benjamin Grange
** Last update Thu Feb 25 21:55:34 2016 Benjamin Grange
*/

#include "lexer.h"

t_result		lex_token(t_file_reader *file)
{
  LexerFunction		lex_func[3];
  int			i;
  t_result		result;

  i = 0;
  lex_func[0] = &lex_config;
  lex_func[1] = &lex_string;
  lex_func[2] = NULL;
  while (lex_func[i])
    {
      result = lex_func[i](file);
      if (result.type == RESULT_TOKEN || result.type == RESULT_ERROR)
	return (result);
      i++;
    }
  return (get_null_result());
}
