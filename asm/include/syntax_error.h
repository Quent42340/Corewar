/*
** SYNTAX_ERROR.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Feb 24 16:49:14 2016 Benjamin Grange
** Last update Thu Feb 25 18:54:10 2016 Benjamin Grange
*/

#ifndef SYNTAX_ERROR_H_
# define SYNTAX_ERROR_H_

# include "position.h"

typedef struct		s_syntax_error
{
  t_position		position;
  char			*error;
}			t_syntax_error;

void			*print_syntax_error(t_file_reader *, void *);
t_syntax_error		generate_syntax_error(t_position, char *);

#endif /* !SYNTAX_ERROR_H_ */
