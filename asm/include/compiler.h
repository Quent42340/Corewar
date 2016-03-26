/*
** compiler.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:33:49 2016 Benjamin Grange
** Last update Fri Mar 25 22:02:56 2016 Benjamin Grange
*/

#ifndef COMPILER_H_
# define COMPILER_H_

# include "asm.h"
# include "program.h"
# include "parser.h"
# include "op.h"

void				write_program(t_program *program);
t_parseres			set_program_config(t_parser *, t_token *, int);
int				open_file(char *name);
char				*get_program_name(char *file);
t_bool				is_param_index(int instru, int i);
t_bool				write_instruction_parameters(int op_num);
t_operation			*create_operation(t_parser *, int);
void				add_param_to_operation(t_operation *op,
						       t_args_type type,
						       unsigned value);
t_bool				push_label(t_parser *, t_token *, size_t);
t_label				*get_label_by_name(t_parser *parser, char *);

#endif /* !COMPILER_H_ */
