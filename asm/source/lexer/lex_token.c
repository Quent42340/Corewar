/*
** lex_token.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 15:12:25 2016 Benjamin Grange
** Last update Thu Feb 25 16:47:26 2016 Benjamin Grange
*/

#include "lexer.h"

t_result		lex_token(t_file_reader *file)
{
  t_result		result;
  char			c;
  result.type = RESULT_TOKEN;
  c = string_reader_next(file);
  printf("Lexing char: %c\n", c);
  return (result);
}
