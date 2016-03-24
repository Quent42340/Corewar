/*
** application.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Feb 23 15:03:50 2016 Quentin Bazin
** Last update Tue Mar 22 17:19:24 2016 Jakob Kellendonk
*/

#include <stdlib.h>
#include "flag.h"

t_err		args_init(t_args *args, int argc, char **argv)
{
  t_info_list	*old;
  t_err		error;

  (void)argc;
  args->program_amount = 0;
  set_default_values(args);
  if ((error = create_prog_info(&args->program_list)))
    return (error);
  while (*argv)
    {
      if (**argv != '-')
	{
	  args->program_list->file_name = *argv;
	  old = args->program_list;
	  if ((error = create_prog_info(&args->program_list)))
	    return (error);
	  old->next = args->program_list;
	  args->program_amount = args->program_amount + 1;
	}
      else if ((error = handle_option_flag(args, argv)))
	return (error);
      argv = argv + 1 + (**argv == '-');
    }
  return (validate_args_state(args));
}

void		args_free(t_args *args)
{
  t_info_list	*next;

  while (args->program_list)
    {
      next = args->program_list->next;
      free(args->program_list);
      args->program_list = next;
    }
}
