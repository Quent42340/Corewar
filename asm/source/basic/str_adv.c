/*
** str_adv.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/basic/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar  1 02:23:04 2016 Benjamin Grange
** Last update Fri Mar 25 15:49:56 2016 Benjamin Grange
*/

#include "basic.h"

int		my_strcmp(char *s1, char *s2)
{
  while (42)
    {
      if (*s1 == '\0' && *s2 == '\0')
	return (1);
      if ((*s1 == '\0' && *s2 != '\0')
	  || (*s2 == '\0' && *s1 != '\0')
	  || (*s1 - *s2) != 0)
	return (0);
      s1++;
      s2++;
    }
  return (1);
}

void		my_cpystr(char *str1, char *str2)
{
  if (str2 != NULL)
    {
      while (*str2)
	{
	  *str1 = *str2;
	  str1++;
	  str2++;
	}
    }
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = my_strlen(dest);
  j = 0;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  return (dest);
}

char	*my_strncpy(char *s1, char *s2, size_t n)
{
  char	*s;

  s = s1;
  while (n > 0 && *s2 != '\0')
    {
      *s++ = *s2++;
      --n;
    }
  while (n > 0)
    {
      *s++ = '\0';
      --n;
    }
  return (s1);
}
