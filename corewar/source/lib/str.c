/*
** str.c for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/source/lib
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Tue Mar 22 14:32:20 2016 Flora Huot
** Last update Tue Mar 22 14:32:20 2016 Flora Huot
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	result;

  result = 0;
  while (str[result])
    result = result + 1;
  return (result);
}

void	my_putstr(char *str, int out)
{
  write(out, str, my_strlen(str));
}

int	my_getnbr(char *str, int *error)
{
  int	sign;
  int	result;

  sign = (*str == '-');
  str = str + sign;
  result = 0;
  *error = 1;
  while (*str)
    {
      if (*str < '0' || *str > '9' || result < -214748364
	  || (*str > '7' + sign && result == -214748364))
	{
	  *error = 1;
	  return (0);
	}
      *error = 0;
      result = result * 10 - *str + '0';
      str = str + 1;
    }
  return (!error * (result * (-(sign * 2) + 1)));
}

int	my_strcmp(char *str_a, char *str_b)
{
  while (*str_a && *str_b && *str_a == *str_b)
    {
      str_a = str_a + 1;
      str_b = str_b + 1;
    }
  return (*str_a - *str_b);
}
