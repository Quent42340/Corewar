/*
** program.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Mon Mar 21 19:45:41 2016 Benjamin Grange
** Last update Fri Mar 25 21:45:41 2016 Benjamin Grange
*/

#ifndef PROGRAM_H_
# define PROGRAM_H_

# include "basic.h"
# include "op.h"

typedef union			u_content
{
  unsigned char			reg;
  unsigned short		index;
  unsigned short		indirect;
  unsigned int			direct;
}				t_content;

typedef struct			s_operation
{
  unsigned char			op_num;
  size_t			nb_param;
  unsigned char			param_type;
  unsigned char			param_size[MAX_ARGS_NUMBER];
  t_content			param_content[MAX_ARGS_NUMBER];
  size_t			size;
  struct s_operation		*next;
}				t_operation;

typedef struct			s_program
{
  char				*file_name;
  t_bool			is_valid;
  t_header			header;
  t_operation			*op;
  t_operation			*last;
}				t_program;

size_t				get_pc(t_program *);

#endif /* !PROGRAM_H_ */
