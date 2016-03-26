/*
** params.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/compiler/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 17:43:41 2016 Benjamin Grange
** Last update Fri Mar 25 17:54:37 2016 Benjamin Grange
*/

#include "compiler.h"

t_bool				write_instruction_parameters(t_token *token)
{
  if (token->content.instruction == INSTRUCTION_LIVE
      || token->content.instruction == INSTRUCTION_ZJMP
      || token->content.instruction == INSTRUCTION_FORK
      || token->content.instruction == INSTRUCTION_LFORK)
    return (0);
  return (1);
}

t_bool				is_param_index(int instru, int i)
{
  if (instru == INSTRUCTION_ZJMP
      || (instru == INSTRUCTION_LDI
	  && i >= 0 && i <= 1)
      || (instru == INSTRUCTION_STI
	  && i >= 1 && i <= 2)
      || instru == INSTRUCTION_FORK)
    return (1);
  return (0);
}

size_t				get_param_size(int instru, int param, int nb)
{
  if (param == T_REG)
    return (1);
  if (param == T_DIR)
    {
      if (is_param_index(instru, nb))
	return (IND_SIZE);
      else
	return (DIR_SIZE);
    }
  if (param == T_IND)
    return (IND_SIZE);
  return (0);
}
