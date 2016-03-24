/*
** asm.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/asm/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:13:52 2016 Benjamin Grange
** Last update Thu Mar 24 13:07:31 2016 Benjamin Grange
*/

#include "asm.h"
#include "lexer.h"
#include "parser.h"
#include "compiler.h"

void			print_comiling_message(char *path)
{
  my_putstr("Compiling file [");
  my_putstr(path);
  my_putstr("]\n");
}

void			compile_file(char *path)
{
  t_program_file	file;
  t_token_list		*token_list;
  t_bool		lexer_result;

  token_list = NULL;
  lexer_result = false;
  print_comiling_message(path);
  file = program_file_create(path);
  if (file.content)
    {
      token_list = lexer(&file, &lexer_result);
      parser(token_list, &file, lexer_result);
      xfree(file.content);
    }
  my_putstr("Compilation done !\n");
}
