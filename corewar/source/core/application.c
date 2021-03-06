/*
** application.c for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Tue Mar 22 17:04:58 2016 Jakob Kellendonk
** Last update Tue Mar 22 17:04:58 2016 Jakob Kellendonk
*/

#include <stdlib.h>
#include "application.h"
#include "run.h"
#include "my_mem.h"

t_err		init_programs(t_application *app, t_args *args)
{
  int		i;
  t_err		error;
  t_info_list	*list;

  i = 0;
  list = args->program_list;
  while (i < app->program_amount)
    {
      if ((error = program_init(app->programs + i, app, list, i)))
	return (error);
      list = list->next;
      i = i + 1;
    }
  return (0);
}

t_err		application_init(t_application *app, t_args *args)
{
  my_memset(app, 0, sizeof(t_application)- sizeof(void *));
  app->death_callback = args->death_callback;
  app->st_callback = args->st_callback;
  app->constants = args->constants;
  app->cycle_to_die = args->cycle_to_die;
  app->programs = malloc(sizeof(t_program) * args->program_amount);
  if (app->programs == NULL)
    return (print_error(ERROR_MALLOC_FAILED));
  my_memset(app->programs, 0, sizeof(t_program) * args->program_amount);
  app->program_amount = args->program_amount;
  return (init_programs(app, args));
}

t_err	application_run(t_application *app)
{
  t_err	ret;

  while (!(ret = tick(app)));
  return (ret);
}

void	application_free(t_application *app)
{
  int	i;

  i = 0;
  while (i < app->program_amount)
    {
      free(app->programs[i].processes);
      i = i + 1;
    }
  free(app->programs);
  free(app->constants);
}
