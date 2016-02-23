/*
** memory_util.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/basic/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 22:40:25 2016 Benjamin Grange
** Last update Tue Feb 23 22:40:41 2016 Benjamin Grange
*/

#include "asm.h"

void		*my_memset(void *src, t_byte c, size_t n)
{
  size_t	i;
  t_byte	*dest;

  i = 0;
  dest = (t_byte *)src;
  while (i < n)
    {
      *(dest + i) = c;
      i++;
    }
  return (src);
}

void		*my_memcpy(void *d, void *s, size_t n)
{
  size_t	i;
  t_byte	*dest;
  t_byte	*src;

  i = 0;
  dest = (t_byte *)d;
  src = (t_byte *)s;
  if (src == NULL)
    return (dest);
  while (i < n)
    {
      *(dest + i) = *(src + i);
      i++;
    }
  return (dest);
}
