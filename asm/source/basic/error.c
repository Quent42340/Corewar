/*
** error.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/basic/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 15:47:28 2016 Benjamin Grange
** Last update Thu Feb 25 15:50:14 2016 Benjamin Grange
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
