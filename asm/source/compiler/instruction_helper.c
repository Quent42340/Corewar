/*
** instruction_helper.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/compiler/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 19:23:16 2016 Benjamin Grange
** Last update Fri Mar 25 19:23:39 2016 Benjamin Grange
*/

#include "compiler.h"

t_bool				write_instruction_parameters(int op_num)
{
  if (op_num == INSTRUCTION_LIVE
      || op_num == INSTRUCTION_ZJMP
      || op_num == INSTRUCTION_FORK
      || op_num == INSTRUCTION_LFORK)
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
