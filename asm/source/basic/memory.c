/*
** memory.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/basic/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 22:37:34 2016 Benjamin Grange
** Last update Tue Feb 23 22:59:27 2016 Benjamin Grange
*/

#include "asm.h"

void	*xmalloc(size_t size)
{
  return (malloc(size));
}

void	xfree(void *ptr)
{
  free(ptr);
}

void	*xrealloc(void *obj, size_t size)
{
  return (realloc(obj, size));
}
