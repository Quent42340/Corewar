/*
** syntax_error.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Feb 24 16:49:14 2016 Benjamin Grange
** Last update Wed Mar 23 01:08:27 2016 Benjamin Grange
*/

#ifndef SYNTAX_ERROR_H_
# define SYNTAX_ERROR_H_

# include "file_reader.h"
# include "position.h"
# include "token.h"

typedef struct		s_syntax_error
{
  t_position		position;
  char			*error;
}			t_syntax_error;

void			*print_syntax_error(t_file_reader *,
					    t_syntax_error *, void *);
void			*print_unexpected_char_error(t_file_reader *reader,
						     void *);
t_syntax_error		generate_syntax_error(t_position, char *);
void			print_line_from_pos(t_file_reader *,
					    t_position, int *);
void			print_line_spaces(t_file_reader *, int, int);
void			raise_warning(void *, t_token_list *, char *);
void			raise_warning_t(void *, t_token *, char *);
void			generate_and_print_se(t_file_reader *,
					      t_position, char *);

#endif /* !SYNTAX_ERROR_H_ */
