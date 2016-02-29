/*
** strutil.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/basic/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 22:37:15 2016 Benjamin Grange
** Last update Fri Feb 26 14:07:44 2016 Benjamin Grange
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

char		*my_strndup(char *str, size_t n)
{
  char		*result;
  size_t	size;

  size = my_strlen(str);
  if (n < size)
    size = n;
  result = xmalloc(sizeof(char) * (size + 1));
  if (!result)
    return (NULL);
  *(result + size) = '\0';
  my_memcpy(result, str, size);
  return (result);
}

char		*my_strchr(char *s, char c)
{
  char		ch;

  ch = c;
  while (*s != ch)
    {
      if (*s == '\0')
	return (0);
      s++;
    }
  return (s);
}

t_bool		is_char_printable(char c)
{
  if (c < 32)
    return (c == '\t');
  else if (c >= 127)
    return (FALSE);
  return (TRUE);
}
