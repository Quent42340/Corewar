/*
** memory.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/basic/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 22:37:34 2016 Benjamin Grange
** Last update Sun Mar 27 15:25:00 2016 Benjamin Grange
*/

#include "asm.h"

void	*xmalloc(size_t size)
{
  void	*ptr;

  ptr = malloc(size);
  if (!ptr)
    {
      my_puterror(RED"Malloc failed !\nLeaving...\n"WHITE);
      exit(1);
    }
  return (ptr);
}

void	xfree(void *ptr)
{
  free(ptr);
}

void	*xrealloc(void *obj, size_t size)
{
  void	*ptr;

  ptr = realloc(obj, size);
  if (!ptr)
    {
      my_puterror(RED"Realloc failed !\nLeaving...\n"WHITE);
      exit(1);
    }
  return (ptr);
}
