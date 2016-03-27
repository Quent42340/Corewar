/*
** instruction.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar  1 17:21:21 2016 Benjamin Grange
** Last update Tue Mar  1 17:24:16 2016 Benjamin Grange
*/

#ifndef INSTRUCTION_H_
# define INSTRUCTION_H_

typedef enum		e_instruction_type
{
  INSTRUCTION_LIVE = 1,
  INSTRUCTION_LD,
  INSTRUCTION_ST,
  INSTRUCTION_ADD,
  INSTRUCTION_SUB,
  INSTRUCTION_AND,
  INSTRUCTION_OR,
  INSTRUCTION_XOR,
  INSTRUCTION_ZJMP,
  INSTRUCTION_LDI,
  INSTRUCTION_STI,
  INSTRUCTION_FORK,
  INSTRUCTION_LLD,
  INSTRUCTION_LLDI,
  INSTRUCTION_LFORK,
  INSTRUCTION_AFF
}			t_instruction_type;

#endif /* !INSTRUCTION_H_ */
