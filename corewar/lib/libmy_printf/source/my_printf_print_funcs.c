/*
** my_printf_print_funcs.c for  in /blinux_home/bazin_q/rendu/PSU_2015_my_printf/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun Nov 08 17:59:41 2015 Quentin Bazin
** Last update Sun Nov 29 19:23:54 2015 Quentin Bazin
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

int	my_printf_print_int(va_list *args, char specifier)
{
  int	arg;

  arg = va_arg(args, int);
  (void)specifier;
  my_put_nbr(arg);
  return (my_int_len(arg) + ((arg < 0) ? 1 : 0));
}

int	my_printf_print_uint(va_list *args, char specifier)
{
  char	*base;

  if (specifier == 'b')
    base = "01";
  else if (specifier == 'u')
    base = "0123456789";
  else if (specifier == 'o')
    base = "01234567";
  else if (specifier == 'x')
    base = "0123456789abcdef";
  else
    base = "0123456789ABCDEF";
  return (my_printf_putulnbr_base(va_arg(args, unsigned int), base));
}

int	my_printf_print_chars(va_list *args, char specifier)
{
  char	*arg;

  if (specifier == 'c')
    {
      my_putchar(va_arg(args, int));
      return (1);
    }
  else if (specifier == 's')
    {
      arg = va_arg(args, char *);
      my_putstr(arg);
      return (my_strlen(arg));
    }
  else
    return (my_printf_showstr_oct(va_arg(args, char *)));
}

int	my_printf_print_ptr_addr(va_list *args, char specifier)
{
  void	*ptr;

  (void)specifier;
  ptr = va_arg(args, void *);
  if (ptr != NULL)
    {
      my_putstr("0x");
      return (my_printf_putulnbr_base((uintptr_t)ptr, "0123456789abcdef") + 2);
    }
  else
    {
      my_putstr("(nil)");
      return (5);
    }
}
