/*
** error.c for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/source/launch
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Wed Mar 23 11:18:08 2016 Flora Huot
** Last update Wed Mar 23 11:18:08 2016 Flora Huot
*/

#include <my.h>
#include <my_printf.h>
#include <stdarg.h>
#include <stdlib.h>
#include "error.h"

void	fill_error_messages(char *messages[ERROR_COUNT])
{
  messages[0] = "Unable to allocate memory";
  messages[1] = "Unable to open file: %s";
  messages[2] = "Unknown option: %s";
  messages[3] = "Missing number after: %s";
  messages[4] = "Value between 1 and 2147483647 expected as parameter for: %s";
  messages[5] = "Value between -2147483648 and 2147483647 expected as"
    " parameter for: %s";
}

void	print_usage(char *program_name)
{
  (void)program_name;
}

t_err	print_error(t_err error, ...)
{
  char	*errors[ERROR_COUNT];
  va_list	args;

  if (error == -1)
    return (error);
  fill_error_messages(errors);
  my_puterr("Error: ");
  va_start(args, error);
  my_vfprintf(2, errors[error - 1], &args);
  va_end(args);
  return (error);
}
