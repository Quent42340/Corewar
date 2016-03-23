/*
** application.c for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Tue Mar 22 17:04:58 2016 Jakob Kellendonk
** Last update Tue Mar 22 18:48:27 2016 Jakob Kellendonk
*/

#include "my_mem.h"

int		read_int(int fd, int *target)
{
  unsigned char	c[4];
  int		r;

  r = 0;
  while ((r = r + read(fd, c, 4)) & 3);
  if (!r)
    {
      /* TODO : File seems empty? */
      return (1);
    }
  *target = char_to_int(c);
  return (0);
}
