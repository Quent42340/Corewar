/*
** run2.c for cprewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Sat Mar 26 23:35:06 2016 Jakob Kellendonk
** Last update Sun Mar 27 01:41:54 2016 Jakob Kellendonk
*/

#include "application.h"
#include "unistd.h"

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
