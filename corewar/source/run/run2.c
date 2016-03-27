/*
** run2.c for cprewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Sat Mar 26 23:35:06 2016 Jakob Kellendonk
** Last update Sat Mar 26 23:35:06 2016 Jakob Kellendonk
*/

#include <unistd.h>
#include "application.h"

t_err	end_game(t_application *app)
{
  int	i;
  int	last_live;

  last_live = 0;
  i = 0;
  while (i < app->program_amount)
    {
      if (app->programs[i].last_live_cycle > last_live)
	last_live = app->programs[i].last_live_cycle;
      i = i + 1;
    }
  i = 0;
  while (i < app->program_amount)
    {
      if (app->programs[i].last_live_cycle == last_live)
	message_win(app->programs + i, i);
      i = i + 1;
    }
  return (ERROR_UNKNOWN);
}

t_err	dump_vm(t_application *app)
{
  int	i;

  i = 0;
  while (i < MEM_SIZE)
    {
      write(1, "0123456789ABCDEF" + (app->memory[i] >> 4), 1);
      write(1, "0123456789ABCDEF" + (app->memory[i] & 15), 1);
      i = i + 1;
      if (!(i & 31))
	write(1, "\n", 1);
    }
  return (ERROR_UNKNOWN);
}
