/*
** program.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Mon Mar 21 19:45:41 2016 Benjamin Grange
** Last update Thu Mar 24 23:16:04 2016 Benjamin Grange
*/

#ifndef PROGRAM_H_
# define PROGRAM_H_

# include "basic.h"
# include "op.h"

typedef struct			s_operation
{
  size_t			nb_params;
  unsigned int			params_type[MAX_ARGS_NUMBER];
  unsigned int			params_value[MAX_ARGS_NUMBER];
  struct s_operation		*next;
}				t_operation;

typedef struct			s_program
{
  t_bool			is_valid;
  t_header			header;
  t_operation			*op;
  t_operation			*last;
}				t_program;

#endif /* !PROGRAM_H_ */
