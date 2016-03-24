/*
** application.c for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Tue Mar 22 17:04:58 2016 Jakob Kellendonk
** Last update Tue Mar 22 18:48:27 2016 Jakob Kellendonk
*/

#include "error.h"
#include "my_mem.h"

t_err		read_char(int fd, char *target, int nb, char *file_name)
{
  int		total;
  int		read_value;

  read_value = read(fd, target, nb);
  total = read_value;
  while (total != nb && read_value > 0)
    {
      read_value = read(fd, target, nb);
      total += read_value;
    }
  if (read_value == 0)
    return (print_error(ERROR_NOT_EXECUTABLE, file_name));
  else if (read_value == -1)
    return (print_error(ERROR_FILE_NAME_NOT_ACCESSIBLE, file_name));
  return (0);
}

t_err		read_int(int fd, int *target, char *file_name)
{
  t_err		error;
  unsigned char	c[4];

  error = read_char(fd, c, 4, file_name);
  if (error)
    return (error);
  *target = char_to_int(c);
  return (0);
}
