/*
** compiler.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:33:49 2016 Benjamin Grange
** Last update Fri Mar 25 18:00:22 2016 Benjamin Grange
*/

#ifndef COMPILER_H_
# define COMPILER_H_

# include "asm.h"
# include "program.h"
# include "parser.h"
# include "op.h"

void				write_program(t_program *program);
t_parseres			set_program_config(t_parser *parser,
						   t_token *t, int i);
void				add_operation(t_parser *parser,
					      t_operation *);
void				add_param_operation(t_operation *, int, int);
t_label				*get_label_by_name(t_parser *, char *);
t_bool				push_label(t_parser *, t_token *, size_t);
t_bool				is_param_index(int instru, int);
t_bool				write_instruction_parameters(t_token *);
int				open_file(char *name);
char				*get_program_name(char *file);
size_t				get_param_size(int instru, int param, int nb);

#endif /* !COMPILER_H_ */
