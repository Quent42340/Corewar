/*
** application.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Feb 23 15:03:50 2016 Quentin Bazin
** Last update Tue Mar  1 12:47:05 2016 Jakob Kellendonk
*/

#include "application.h"

int	create_prog_info(t_info_list **new)
{
  *new = malloc(sizeof(t_info_list));
  if (*new == NULL)
    {
      my_putstr("Malloc returned null!\n", 2);
      return (1);
    }
  (*new)->file_name = NULL;
  (*new)->live_code = -1;
  (*new)->address = -1;
  (*new)->next = NULL;
  return (0);
}

int		handle_option_flag(t_application *app, char **flags)
{
  int		*target;

  if (!my_strcmp(*flags, "-a"))
    target = &app->program_list->address;
  else if (!my_strcmp(*flags, "-n"))
    target = &app->program_list->live_code;
  else if (!my_strcmp(*flags, "-dump"))
    target = &app->dump_cycle;
  else
    {
      my_putstr("Error: Unknow option ", 2);
      my_putstr(*flags, 2);
      my_putstr("\n", 2);
      return (1);
    }
  if (!flags[1])
    {
      my_putstr("Error: Missing number after ", 2);
      my_putstr(*flags, 2);
      my_putstr(" argument\n", 2);
      return (1);
    }
  return (set_option_flag(app, flags, target));
}

int		application_init(t_application *app, int argc, char **argv)
{
  t_info_list	*old;

  (void)argc;
  set_default_values(app);
  if (create_prog_info(&app->program_list))
    return (1);
  while (*argv)
    {
      if (**argv != '-')
	{
	  app->program_list->file_name = *argv;
	  old = app->program_list;
	  if (create_prog_info(&app->program_list))
	    return (1);
	  old->next = app->program_list;
	}
      else if (handle_option_flag(app, argv))
	return (1);
      argv = argv + 1 + (**argv == '-');
    }
  return (validate_app_state(app));
}

int	application_run(t_application *app)
{
  (void)app;
  return (0);
}

int	application_free(t_application *app)
{
  (void)app;
  return (0);
}
