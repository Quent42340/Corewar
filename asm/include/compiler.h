/*
** compiler.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:33:49 2016 Benjamin Grange
** Last update Thu Mar 24 23:32:17 2016 Benjamin Grange
*/

#ifndef COMPILER_H_
# define COMPILER_H_

# include "asm.h"
# include "program.h"
# include "parser.h"
# include "op.h"

t_parseres			set_program_config(t_parser *parser,
						   t_token *t, int i);
void				add_operation(t_parser *parser,
					      t_operation *);
void				add_param_operation(t_operation *op,
						    int type,
						    int value);

#endif /* !COMPILER_H_ */
