/*
** asm.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/asm/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:13:52 2016 Benjamin Grange
** Last update Mon Feb 29 22:11:05 2016 Benjamin Grange
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
  t_byte		*compiled_file;

  print_comiling_message(path);
  file = program_file_create(path);
  if (file.content)
    {
      token_list = lexer(&file);
      compiled_file = parser(token_list);
      if (!compiled_file)
	compile(compiled_file);
      xfree(file.content);
    }
  my_putstr("Compilation terminated !\n");
}
