/*
** vm_copy.h for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Thu Mar 24 22:24:22 2016 Jakob Kellendonk
** Last update Mon Mar 28 01:08:06 2016 Jakob Kellendonk
*/

#ifndef VM_COPY_H_
# define VM_COPY_H_

# include "my_mem.h"
# include "application.h"

unsigned char	*set_args(t_application *application, t_process *process,
			  unsigned char format, unsigned char *buffs[2]);
unsigned char	*get_args(t_application *application, t_process *process,
			  unsigned char format, unsigned char *buffs[2]);
int	get_args_index(t_application *application, t_process *process,
			  unsigned char format, unsigned char *buffs[2]);
void	vm_cpyfrom(t_application *application, int offset,
		   unsigned char *buf, int amount);
void	vm_cpyto(t_application *application, int offset,
		 unsigned char *buf, int amount);

#endif /* VM_COPY_H_*/
