/*
** getnbr.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/basic/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar  1 18:38:35 2016 Benjamin Grange
** Last update Sun Mar 27 04:35:14 2016 Benjamin Grange
*/

#include "basic.h"

int			my_isnum(char *str)
{
  if (!*str)
    return (0);
  if (*str == '+' || *str == '-')
    str++;
  while (*str)
    {
      if (*str < '0' || *str > '9')
	return (0);
      str++;
    }
  return (1);
}

int			my_getnbr(char *str)
{
  int			i;
  int			j;

  j = 1;
  i = 0;
  if (*str == '+' || *str == '-')
    {
      j *= -(*str == '-');
      str++;
    }
  while (*str)
    {
      i *= 10;
      i += *str - '0';
      str++;
    }
  return (i * j);
}
