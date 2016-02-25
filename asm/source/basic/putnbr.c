/*
** putnbr.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/basic/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 15:37:50 2016 Benjamin Grange
** Last update Thu Feb 25 15:51:21 2016 Benjamin Grange
*/

#include "basic.h"

ssize_t		my_putnbr_error(int nbr)
{
  ssize_t	size;

  size = 0;
  if (nbr < 0)
    {
      if (nbr == -2147483648)
	return (my_putstr("-2147483648"));
      else
	{
	  size += my_putchar('-');
	  nbr *= (-1);
	}
    }
  if (nbr >= 10)
    size += my_putnbr_error(nbr / 10);
  return (my_putchar_error('0' + nbr % 10) + size);
}
