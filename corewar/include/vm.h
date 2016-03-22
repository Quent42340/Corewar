/*
** vm.h for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Tue Mar 22 11:49:47 2016 Jakob Kellendonk
** Last update Tue Mar 22 16:27:59 2016 Jakob Kellendonk
*/

#ifndef VM_H_
# define VM_H_

# include "op.h"

typedef struct	s_process
{
  int		cycles_left;
  int		carry;
  int		pc;
  unsigned char	registre[REG_SIZE][REG_NUMBER];
}		t_process;

typedef struct	s_program
{
  int		live;
  t_process	*processes;
  int		did_live;
}		t_program;

typedef struct	s_vm
{
  unsigned char	memory[MEM_SIZE];
  t_program	*programs;
  int		cycle_to_die;
  int		cycle;
  int		live_amount;
}		t_vm;

#endif /* !VM_H_ */
