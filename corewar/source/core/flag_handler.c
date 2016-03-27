/*
** flag_handler.c for  in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Mon Feb 29 12:51:47 2016 Jakob Kellendonk
** Last update Sun Mar 27 23:27:25 2016 Jakob Kellendonk
*/

#include <stdlib.h>
#include "flag.h"
#include "my_mem.h"
#include "program.h"

t_err	set_option_flag(t_args *args, char **flags, int *target)
{
  int	error;

  *target = my_getnbr_error(flags[1], &error);
  if (error)
    return (print_error(ERROR_INTEGER_EXPECTED, *flags));
  if (*target <= 0 && target == &args->constants->dump_cycle)
    return (print_error(ERROR_POSITIVE_NUMBER_EXPECTED, *flags));
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

void		verify_prog_numbers2(t_args *args, t_info_list *tmpi)
{
  t_info_list	*tmpj;

  tmpi->live_code = 0;
  tmpj = args->program_list;
  while (tmpj->file_name)
    {
      if (tmpi != tmpj && tmpi->live_code == tmpj->live_code)
	{
	  tmpj = tmpi->next;
	  tmpi->live_code = tmpi->live_code + 1;
	}
      else
	tmpj = tmpj->next;
    }
}

t_err		verify_prog_numbers(t_args *args)
{
  t_info_list	*tmpi;
  t_info_list	*tmpj;

  tmpi = args->program_list;
  while (tmpi->file_name)
    {
      if (tmpi->live_code == -1)
	verify_prog_numbers2(args, tmpi);
      else
	{
	  tmpj = args->program_list;
	  while (tmpj->file_name)
	    {
	      if (tmpi != tmpj && tmpi->live_code == tmpj->live_code)
		return (print_error(ERROR_TWO_SAME_LIVE_CODES,
				    tmpi->live_code));
	      tmpj = tmpj->next;
	    }
	}
      tmpi = tmpi->next;
    }
  return (0);
}

t_err	validate_args_state(t_args *args, t_info_list *last)
{
  t_info_list	*tmpi;

  if (args->program_amount < 2 || args->program_amount > 4)
    return (print_error(ERROR_WRONG_PROGRAM_AMOUNT));
  if (last->live_code != -1 || last->address != -1)
    {
      my_putstr_out("Error: specified program's ", 2);
      if (last->live_code != -1)
	my_putstr_out("live number ", 2);
      if (last->live_code != -1 && last->address != -1)
	my_putstr_out("and ", 2);
      if (last->address != -1)
	my_putstr_out("starting address ", 2);
      my_putstr_out("but didn't specify program's file.\n", 2);
      return (print_error(ERROR_UNKNOWN));
    }
  tmpi = args->program_list;
  while (tmpi->file_name)
    {
      if (tmpi->address != -1)
	tmpi->address = (tmpi->address + MEM_SIZE) % MEM_SIZE;
      tmpi = tmpi->next;
    }
  return (verify_prog_numbers(args));
}
