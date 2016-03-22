/*
** flag_handler.c for  in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Mon Feb 29 12:51:47 2016 Jakob Kellendonk
** Last update Tue Mar 22 16:59:05 2016 Jakob Kellendonk
*/

#include "application.h"
#include "my.h"

int	set_option_flag(t_args *args, char **flags, int *target)
{
  int	error;

  *target = my_getnbr(flags[1], &error);
  if (*target <= 0 && target == &args->constants->dump_cycle)
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

int	set_default_values(t_args *args)
{
  args->constants = malloc(sizeof(t_constants));
  if (!args->constants)
    return (1);
  args->constants->dump_cycle = -1;
  args->cycle_to_die = CYCLE_TO_DIE;
  args->constants->cycle_delta = CYCLE_DELTA;
  args->constants->nbr_live = NBR_LIVE;
  return (0);
}

int	validate_args_state(t_args *args)
{
  if (args->program_list->live_code != -1 || args->program_list->address != -1)
    {
      my_putstr("Error: specified program's ", 2);
      if (args->program_list->live_code != -1)
	my_putstr("live number ", 2);
      if (args->program_list->live_code != -1
	  && args->program_list->address != -1)
	my_putstr("and ", 2);
      if (args->program_list->address != -1)
	my_putstr("starting address ", 2);
      my_putstr("but didn't specifie program's file.\n", 2);
      return (1);
    }
  return (0);
}
