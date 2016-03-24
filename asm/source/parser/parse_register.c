/*
** parse_register.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Mar 24 16:27:22 2016 Benjamin Grange
** Last update Thu Mar 24 23:33:56 2016 Benjamin Grange
*/

#include "compiler.h"
#include "parser.h"

t_parseres			parse_register(t_token *token,
					       t_operation *op)
{
  add_param_operation(op, T_REG, token->content.int_value);
  return (get_instruction_result());
}
