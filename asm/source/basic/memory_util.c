/*
** memory_util.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/basic/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 22:40:25 2016 Benjamin Grange
** Last update Mon Mar 21 22:23:10 2016 Benjamin Grange
*/

#include "asm.h"

void			*my_memset(void *src,
				   register char c,
				   register size_t n)
{
  register size_t	t;
  register t_byte	*s;
  register t_uint	word;

  s = src;
  word = (c << 24) + (c << 16) + (c << 8) + c;
  if (n >= 4)
    {
      if ((t = ((unsigned long)s & WMASK) != 0))
	{
	  t = WSIZE - t;
	  n -= t;
	  while (t-- > 0)
	    *s++ = c;
	}
      while (n >= 4)
	{
	  *(unsigned int *)s = word;
	  s += 4;
	  n -= 4;
	}
    }
  while (n--)
    *s++ = c;
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
