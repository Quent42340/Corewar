/*
** file.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/file/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 22:26:50 2016 Benjamin Grange
** Last update Wed Feb 24 13:11:07 2016 Benjamin Grange
*/

#include "asm.h"

static char		*read_file_content(int fd)
{
  char			*content;
  unsigned int		length;
  int			read_output;

  length = 0;
  content = NULL;
  while (42)
    {
      content = xrealloc(content, length + 4096 + 1);
      if (!content)
	return (NULL);
      read_output = read(fd, content + length, 4096);
      if (read_output < 0)
	return (NULL);
      length += read_output;
      content[length] = '\0';
      if (my_strlen(content) != length)
	{
	  xfree(content);
	  return (NULL);
	}
      if (read_output != 4096)
	break;
    }
  return (content);
}

static char		*open_and_read_file_content(char *path)
{
  char			*content;
  int			fd;

  fd = open(path, O_RDONLY, S_IRWXU);
  content = NULL;
  if (fd > 0)
    {
      content = read_file_content(fd);
      close(fd);
    }
  return (content);
}

static char		*get_file_name(char *path)
{
  ssize_t		i;

  if (path != NULL)
    {
      i = my_strlen(path) - 1;
      while (i >= 0)
	{
	  if (path[i] == '/')
	    return (path + i + 1);
	  i--;
	}
    }
  return (path);
}

t_program_file		program_file_create(char *path)
{
  t_program_file	file;

  file.path = path;
  file.name = get_file_name(path);
  file.content = open_and_read_file_content(path);
  file.file_size = my_strlen(path);
  return (file);
}
