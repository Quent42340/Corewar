/*
** flag_handler2.c for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Tue Mar  1 12:33:43 2016 Jakob Kellendonk
** Last update Tue Mar  1 12:48:23 2016 Jakob Kellendonk
*/

#include "application.h"

void	set_default_values(t_application *app)
{
  app->dump_cycle = -1;
  app->cycle_to_die = CYCLE_TO_DIE;
  app->cycle_delta = CYCLE_DELTA;
  app->nbr_live = NBR_LIVE;
}

int	validate_app_state(t_application *app)
{
  if (app->program_list->live_code != -1 || app->program_list->address != -1)
    {
      my_putstr("Error: specified program's ", 2);
      if (app->program_list->live_code != -1)
	my_putstr("live number ", 2);
      if (app->program_list->live_code != -1
	  && app->program_list->address != -1)
	my_putstr("and ", 2);
      if (app->program_list->address != -1)
	my_putstr("starting address ", 2);
      my_putstr("but didn't specifie program's file.\n", 2);
      return (1);
    }
  return (0);
}
