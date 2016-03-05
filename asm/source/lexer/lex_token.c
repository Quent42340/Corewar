/*
** lex_token.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 15:12:25 2016 Benjamin Grange
** Last update Fri Mar  4 22:05:37 2016 Benjamin Grange
*/

#include "lexer.h"

t_result		lex_token(t_file_reader *file)
{
  LexerFunction		lex_func[8];
  int			i;
  t_result		result;

  i = 0;
  lex_func[i++] = &lex_string;
  lex_func[i++] = &lex_comment;
  lex_func[i++] = &lex_multiline_comment;
  lex_func[i++] = &lex_label;
  lex_func[i++] = &lex_direct_label;
  lex_func[i++] = &lex_operator;
  lex_func[i++] = &lex_identifiers;
  lex_func[i++] = NULL;
  i = 0;
  while (lex_func[i])
    {
      result = lex_func[i](file);
      if (result.type == RESULT_TOKEN || result.type == RESULT_ERROR)
	return (result);
      i++;
    }
  return (get_null_result());
}
