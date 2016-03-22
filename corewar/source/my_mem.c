/*
** my_memset.c for corewar in /home/kellen_j/rendu/PSU_2015_tetris
** 
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
** 
** Started on  Tue Mar 22 12:45:49 2016 Benjamin Grange
** Last update Tue Mar 22 13:18:41 2016 Jakob Kellendonk
*/

#include "my_mem.h"

void				*my_memcpy(void *src,
					   void *dest,
					   register size_t n)
{
  if (n >= WSIZE)
    {
      while ((((unsigned long)src + n) & WMASK))
	{
	  n = n - 1;
	  ((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
      while (n >= WSIZE)
	{
	  n = n - WSIZE;
	  ((unsigned int *)dest)[n >> WSIZE] =
	    ((unsigned int *)src)[n >> WSIZE];
	}
    }
  while (n > 0)
    {
      n = n - 1;
      ((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
    }
  return (dest);
}


void				*my_memset(void *src,
					   register char c,
					   register size_t n)
{
  register size_t		t;
  register unsigned char	*s;
  register unsigned int		word;

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

inline void	my_bzero(void *s, size_t n)
{
  my_memset(s, 0, n);
}
