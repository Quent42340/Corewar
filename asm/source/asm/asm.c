/*
** asm.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/asm/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:13:52 2016 Benjamin Grange
** Last update Sun Mar 27 04:18:41 2016 Benjamin Grange
*/

#include "asm.h"
#include "lexer.h"
#include "parser.h"
#include "compiler.h"

void			compile_file(char *path)
{
  t_program_file	file;
  t_token_list		*token_list;
  t_bool		lexer_result;
  t_program		program;

  token_list = NULL;
  lexer_result = false;
  file = program_file_create(path);
  if (file.content)
    {
      token_list = lexer(&file, &lexer_result);
      if (LEXER_DEBUG)
	lexer_result = false;
      program = parser(token_list, &file, lexer_result);
      write_program(&program);
      free_program(&program);
      xfree(file.content);
    }
}
