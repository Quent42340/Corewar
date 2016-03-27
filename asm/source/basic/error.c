/*
** error.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/basic/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 15:47:28 2016 Benjamin Grange
** Last update Tue Mar  1 01:29:28 2016 Benjamin Grange
*/

#include "basic.h"

ssize_t		my_putchar_error(char c)
{
  return (write(2, &c, 1));
}

ssize_t		my_puterror(char *str)
{
  if (!str)
    return (0);
  return (write(2, str, my_strlen(str)));
}

void		*print_error_n(char *str)
{
  my_puterror(str);
  return (NULL);
}

int		print_error_i(char *str, int i)
{
  my_puterror(str);
  return (i);
}
