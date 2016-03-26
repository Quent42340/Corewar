/*
** application.c for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Tue Mar 22 17:04:58 2016 Jakob Kellendonk
** Last update Sat Mar 26 14:04:02 2016 Jakob Kellendonk
*/

#include <stdlib.h>
#include "application.h"
#include "run.h"
#include "my_mem.h"

t_err		application_init(t_application *app, t_args *args)
{
  int		i;
  t_err		error;
  t_info_list	*list;

  app->constants = args->constants;
  app->last_limit_hit = 0;
  app->cycle_to_die = args->cycle_to_die;
  app->programs = malloc(sizeof(t_program) * args->program_amount);
  if (app->programs == NULL)
    return (print_error(ERROR_MALLOC_FAILED));
  app->program_amount = args->program_amount;
  app->live_count = 0;
  my_memset(app->memory, 0, MEM_SIZE);
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

t_err	application_run(t_application *app)
{
  t_err	ret;

  while (!(ret = tick(app)));
  return (ret);
}

void	application_free(t_application *app)
{
  (void)app;
}
