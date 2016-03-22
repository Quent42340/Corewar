/*
** flag_handler.c for  in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Mon Feb 29 12:51:47 2016 Jakob Kellendonk
** Last update Tue Mar  1 16:37:57 2016 Jakob Kellendonk
*/

#include "application.h"

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

int	set_option_flag(t_application *app, char **flags, int *target)
{
  int	error;

  (void)app;
  *target = my_getnbr(flags[1], &error);
  if (*target <= 0 && target == &app->dump_cycle)
    {
      my_putstr("Error: Value betweeen 1 and 2147483647"	\
		" expected as parameter for ", 2);
      my_putstr(*flags, 2);
      my_putstr("\n", 1);
      return (1);
    }
  if (error)
    {
      my_putstr("Error: Value betweeen -2147483648 and 2147483647" \
		" expected as parameter for ", 2);
      my_putstr(*flags, 2);
      my_putstr("\n", 1);
      return (1);
    }
  return (0);
}
