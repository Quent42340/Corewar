/*
** putstr.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/basic/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 22:34:52 2016 Benjamin Grange
** Last update Tue Feb 23 22:35:33 2016 Benjamin Grange
*/

# include "asm.h"

ssize_t		my_putchar(char c)
{
  return (write(1, &c, 1));
}

ssize_t		my_putstr(char *str)
{
  if (!str)
    return (0);
  return (write(1, str, my_strlen(str)));
}
