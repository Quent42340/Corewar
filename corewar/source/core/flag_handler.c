/*
** flag_handler.c for  in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Mon Feb 29 12:51:47 2016 Jakob Kellendonk
** Last update Tue Mar 22 16:59:05 2016 Jakob Kellendonk
*/

#include <stdlib.h>
#include "flag.h"
#include "my_mem.h"
#include "program.h"

t_err	set_option_flag(t_args *args, char **flags, int *target)
{
  int	error;

  *target = my_getnbr_error(flags[1], &error);
  if (*target <= 0 && target == &args->constants->dump_cycle)
    return (print_error(ERROR_POSITIVE_NUMBER_EXPECTED, *flags));
  if (error)
    return (print_error(ERROR_INTEGER_EXPECTED, *flags));
  return (0);
}

t_err	set_default_values(t_args *args)
{
  args->constants = malloc(sizeof(t_constants));
  if (!args->constants)
    return (print_error(ERROR_MALLOC_FAILED));
  args->constants->dump_cycle = -1;
  args->cycle_to_die = CYCLE_TO_DIE;
  args->constants->cycle_delta = CYCLE_DELTA;
  args->constants->nbr_live = NBR_LIVE;
  return (0);
}

t_err	validate_args_state(t_args *args)
{
  if (args->program_amount < 2 || args->program_amount > 4)
    return (print_error(ERROR_TOO_MANY_PROGRAMS));
  if (args->program_list->live_code != -1 || args->program_list->address != -1)
    {
      my_putstr_out("Error: specified program's ", 2);
      if (args->program_list->live_code != -1)
	my_putstr_out("live number ", 2);
      if (args->program_list->live_code != -1
	  && args->program_list->address != -1)
	my_putstr_out("and ", 2);
      if (args->program_list->address != -1)
	my_putstr_out("starting address ", 2);
      my_putstr_out("but didn't specify program's file.\n", 2);
      return (print_error(ERROR_UNKNOWN));
    }
  return (0);
}
