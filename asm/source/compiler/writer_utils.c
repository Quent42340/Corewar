/*
** writer_utils.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/compiler/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 15:59:53 2016 Benjamin Grange
** Last update Sat Mar 26 17:15:07 2016 Benjamin Grange
*/

#include "compiler.h"

char			*get_program_name(char *file)
{
  char				*name;

  if (!file)
    return (NULL);
  if (my_strlen(file) > 2
	  && my_strcmp(file + my_strlen(file) - 2, ".s"))
    {
      name = xmalloc(my_strlen(file) + 2);
      if (!name)
	return (NULL);
      my_memset(name, 0, my_strlen(file) + 4);
      my_strncpy(name, file, my_strlen(file) - 1);
    }
  else
    {
      name = xmalloc(my_strlen(file) + 4);
      if (!name)
	return (NULL);
      my_memset(name, 0, my_strlen(file) + 4);
      my_cpystr(name, file);
      my_strcat(name, ".");

    }
  my_strcat(name, "cor");
  return (name);
}

int			open_file(char *name)
{
  int			fd;

  if (!name)
    return (-1);
  fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd < 0)
    {
      my_puterror(RED"Can't open file \"");
      my_puterror(name);
      my_puterror("\" !\n"WHITE);
    }
  xfree(name);
  return (fd);
}
