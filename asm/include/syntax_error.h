/*
** syntax_error.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Feb 24 16:49:14 2016 Benjamin Grange
** Last update Wed Feb 24 16:51:41 2016 Benjamin Grange
*/

#ifndef SYNTAX_ERROR_H_
# define SYNTAX_ERROR_H_

# include "position.h"

typedef enum		e_syntax_error_enum
{
  syntax_error_bad_arguments,
  syntax_error_bad_label_name,
  syntax_error_unkown_instruction
}			t_syntax_error_enum;

typedef struct		s_syntax_error
{
  t_position		position;
  t_syntax_error_enum	error;
}			t_syntax_error;

#endif /* !SYNTAX_ERROR_H_ */
