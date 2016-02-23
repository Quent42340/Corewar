/*
** asm.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/asm/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:13:52 2016 Benjamin Grange
** Last update Tue Feb 23 23:30:25 2016 Benjamin Grange
*/

#include "asm.h"

void			compile_file(char *path)
{
  t_asm_program_file	file;
  t_asm_token_list	*token_list;
  t_byte		*compiled_file;

  file = program_file_create(path);
  if (file.content)
    {
      token_list = lexer(&file);
      compiled_file = parser(token_list);
      if (!compile_file)
	compile(compile_file);
    }
}
