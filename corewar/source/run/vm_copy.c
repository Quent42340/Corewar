/*
** vm_copy.c for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Thu Mar 24 18:19:59 2016 Jakob Kellendonk
** Last update Sun Mar 27 14:55:33 2016 Jakob Kellendonk
*/

# include "application.h"
# include "vm_copy.h"

unsigned char	*set_args(t_application *application, t_process *process,
			  unsigned char format, unsigned char *buffs[2])
{
  if (format == 1)
    {
      my_memcpy(process->registre[buffs[1][0] - 1], buffs[0], REG_SIZE);
      return (buffs[1] + 1);
    }
  if (format == 3)
    {
      vm_cpyto(application, process->pc + (char_to_short(buffs[1]) % IDX_MOD),
	       buffs[0], REG_SIZE);
      if (application->st_callback)
	application->st_callback(application, process->parent,
				 process->pc + (char_to_short(buffs[1])
						% IDX_MOD), REG_SIZE);
      return (buffs[1] + 2);
    }
  return (NULL);
}

unsigned char	*get_args(t_application *application, t_process *process,
			  unsigned char format, unsigned char *buffs[2])
{
  if (format == 1)
    {
      my_memcpy(buffs[0], process->registre[buffs[1][0] - 1], REG_SIZE);
      return (buffs[1] + 1);
    }
  if (format == 2)
    {
      my_memcpy(buffs[0], buffs[1], REG_SIZE);
      return (buffs[1] + 4);
    }
  if (format == 3)
    {
      vm_cpyfrom(application, process->pc
		 + (char_to_short(buffs[1]) % IDX_MOD),
		 buffs[0], REG_SIZE);
      return (buffs[1] + 2);
    }
  return (NULL);
}

void	vm_cpyto(t_application *application, int offset,
		 unsigned char *buf, int amount)
{
  offset = ((offset % MEM_SIZE) + MEM_SIZE) % MEM_SIZE;
  if (offset + amount > MEM_SIZE)
    {
      vm_cpyto(application, offset, buf, MEM_SIZE - offset);
      vm_cpyto(application, 0, buf, offset + amount - MEM_SIZE);
    }
  else
    my_memcpy(application->memory + offset, buf, amount);
}

void	vm_cpyfrom(t_application *application, int offset,
		   unsigned char *buf, int amount)
{
  offset = ((offset % MEM_SIZE)+ MEM_SIZE) % MEM_SIZE;
  if (offset + amount > MEM_SIZE)
    {
      vm_cpyfrom(application, offset, buf, MEM_SIZE - offset);
      vm_cpyfrom(application, 0, buf, offset + amount - MEM_SIZE);
    }
  else
    my_memcpy(buf, application->memory + offset, amount);
}
