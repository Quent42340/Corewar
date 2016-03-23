/*
** application.c for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Tue Mar 22 17:04:58 2016 Jakob Kellendonk
** Last update Tue Mar 22 18:43:58 2016 Jakob Kellendonk
*/

#include "application.h"

t_err		application_init(t_application *app, t_args *args)
{
  int		i;
  t_err		error;
  t_info_list	*list;

  app->constants = args->constants;
  app->cycle_to_die = args->cycle_to_die;
  app->programs = malloc(sizeof(t_program) * args->program_amount);
  if (app->programs == NULL)
    return (print_error(ERROR_MALLOC_FAILED));
  app->program_amount = args->program_amount;
  i = 0;
  list = args->program_list;
  while (i < app->program_amount)
    {
      if ((error = program_init(&app->programs[i], app, list)))
	return (error);
      list = list->next;
      i = i + 1;
    }
  return (0);
}

void	application_run(t_application *app)
{
  (void)app;
}

void	application_free(t_application *app)
{
  (void)app;
}
