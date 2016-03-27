/*
** lex_keyword.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar  1 02:05:39 2016 Benjamin Grange
** Last update Fri Mar  4 22:05:12 2016 Benjamin Grange
*/

#include "lexer.h"

t_result		create_unkown_identifer_result(t_position begin,
						       char *string)
{
  char			*error;
  t_result		result;

  error = xmalloc(my_strlen("Unknown identifier \"\"") + my_strlen(string) + 1);
  if (error == NULL)
    return create_result_from_se(begin, "Unknown identifier");
  my_cpystr(error, "Unknown identifier \"");
  my_cpystr(error + 20, string);
  my_cpystr(error + 20 + my_strlen(string), "\"");
  error[21 + my_strlen(string)] = '\0';
  result = create_result_from_se(begin, error);
  xfree(error);
  return (result);
}

t_result		lex_keyword(t_file_reader *reader,
				    t_position begin,
				    char *string)
{
  int			i;
  KeywordFunc		keyword_func[5];
  t_result		result;

  i = 0;
  keyword_func[i++] = &lex_config;
  keyword_func[i++] = &lex_register;
  keyword_func[i++] = &lex_instruction;
  keyword_func[i++] = &lex_integer;
  keyword_func[i++] = NULL;
  i = 0;
  while (keyword_func[i])
    {
      result = keyword_func[i](reader, begin, string);
      if (result.type == RESULT_TOKEN || result.type == RESULT_ERROR)
	return (result);
      i++;
    }
  return (create_unkown_identifer_result(begin, string));
}
