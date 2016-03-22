/*
** vm.h for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Tue Mar 22 11:49:47 2016 Jakob Kellendonk
** Last update Tue Mar 22 14:20:09 2016 Jakob Kellendonk
*/

#ifndef VM_H_
# define VM_H_

# include "op.h"

typedef struct	s_process
{
  int		pc;
  unsigned char	regitre[REG_NUMBER];
}		t_process;

typedef struct	s_vm
{
  unsigned char	memory[MEM_SIZE];
  t_process	*processes;
}		t_vm;

#endif /* !VM_H_ */
