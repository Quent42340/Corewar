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
#include "flag.h"

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
