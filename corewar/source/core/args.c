/*
** application.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Feb 23 15:03:50 2016 Quentin Bazin
** Last update Sat Mar 26 18:28:12 2016 Jakob Kellendonk
*/

#include <stdlib.h>
#include "flag.h"

t_err		args_init(t_args *args, char **argv)
{
  t_info_list	*current;
  t_err		error;

  args->program_amount = 0;
  args->death_callback = NULL;
  args->st_callback = NULL;
  if ((error = set_default_values(args))
      || (error = create_prog_info(&args->program_list)))
    return (error);
  current = args->program_list;
  while (*argv)
    {
      if (**argv != '-')
	{
	  current->file_name = *argv;
	  if ((error = create_prog_info(&current->next)))
	    return (error);
	  current = current->next;
	  args->program_amount = args->program_amount + 1;
	}
      else if ((error = handle_option_flag(args, argv)))
	return (error);
      argv = argv + 1 + (**argv == '-');
    }
  return (validate_args_state(args, current));
}

void		args_free(t_args *args)
{
  t_info_list	*next;

  while (args->program_list->file_name)
    {
      next = args->program_list->next;
      free(args->program_list);
      args->program_list = next;
    }
}
