/*
** lexer.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:32:19 2016 Benjamin Grange
** Last update Wed Feb 24 16:48:48 2016 Benjamin Grange
*/

#ifndef LEXER_H_
# define LEXER_H_

# include "asm.h"

typedef enum		e_result_type
{
  result_token,
  result_null,
  result_error
}			t_result_type;

typedef union		s_result
{
  t_result_type		type;
}			t_result;

t_token_list	*lexer(t_program_file *file);

#endif /* !LEXER_H_ */
