/*
** strutil.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/basic/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 22:37:15 2016 Benjamin Grange
** Last update Tue Feb 23 22:50:19 2016 Benjamin Grange
*/

#include "asm.h"

ssize_t		my_strlen(char *str)
{
  ssize_t	i;

  i = 0;
  if (!str)
    return (0);
  while (*(str + i))
    i++;
  return (i);
}

char		*my_strdup(char *str)
{
  char		*result;
  size_t	size;

  size = my_strlen(str);
  if (str != NULL && (result = xmalloc(sizeof(char) * (size + 1))) != NULL)
    {
      my_memcpy(result, str, size);
      *(result + size) = '\0';
      return (result);
    }
  return (NULL);
}
