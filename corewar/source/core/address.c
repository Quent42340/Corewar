/*
** address.c for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/source/core
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Sun Mar 27 23:00:03 2016 Flora Huot
** Last update Sun Mar 27 23:00:03 2016 Flora Huot
*/

#include "application.h"

t_err		address_check(t_application *app, t_program *program,
			    t_info_list *list)
{
  int		i;

  i = 0;
  while (app->programs + i != program)
    {
      if ((((app->programs[i].processes[0].pc - list->address)
	   % MEM_SIZE) + MEM_SIZE) % MEM_SIZE < program->info.prog_size
	  || (((list->address - app->programs[i].processes[0].pc)
	       % MEM_SIZE) + MEM_SIZE) % MEM_SIZE
	  < app->programs[i].info.prog_size)
	return (print_error(ERROR_OVERLAP));
      i = i + 1;
    }
  return (0);
}

t_err		set_address(t_application *app, t_program *program,
			    t_info_list *list)
{
  int		i;
  t_info_list	*tmp;
  int		d;

  if (list->address == -1)
    {
      i = 0;
      tmp = list;
      while (tmp->address == -1 && tmp->file_name)
	{
	  tmp = tmp->next;
	  i = i + 1;
	}
      list->address = 0;
      if (i && program->index)
	{
	  d = ((tmp->address == - 1) ? app->programs->processes->pc : tmp->address)
	    - app->programs[program->index - 1].processes->pc;
	  list->address = app->programs[program->index - 1].processes->pc
	    + ((d <= 0) * MEM_SIZE + d) / (i + 1);
	}
    }
  return (address_check(app, program, list));
}

