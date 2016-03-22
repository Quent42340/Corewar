/*
** flag_handler.c for  in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Mon Feb 29 12:51:47 2016 Jakob Kellendonk
** Last update Tue Mar  1 16:37:57 2016 Jakob Kellendonk
*/

#include "application.h"
#include "my.h"

int	set_option_flag(t_application *app, char **flags, int *target)
{
  int	error;

  (void)app;
  *target = my_getnbr(flags[1], &error);
  if (*target <= 0 && target == &app->dump_cycle)
    {
      my_putstr("Error: Value betweeen 1 and 2147483647"	\
		" expected as parameter for ", 2);
      my_putstr(*flags, 2);
      my_putstr("\n", 1);
      return (1);
    }
  if (error)
    {
      my_putstr("Error: Value betweeen -2147483648 and 2147483647" \
		" expected as parameter for ", 2);
      my_putstr(*flags, 2);
      my_putstr("\n", 1);
      return (1);
    }
  return (0);
}

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
