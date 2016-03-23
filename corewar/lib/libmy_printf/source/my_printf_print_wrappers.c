/*
** my_printf_print_wrappers.c for  in /blinux_home/bazin_q/rendu/
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun Nov 29 19:08:04 2015 Quentin Bazin
** Last update Sun Nov 29 19:31:15 2015 Quentin Bazin
*/

#include <my.h>
#include <stdlib.h>
#include "my_printf.h"

int	my_printf_putchar(char c)
{
  my_putchar(c);
  return (1);
}

int	my_printf_putstr(char *str)
{
  my_putstr(str);
  return (my_strlen(str));
}

uint64_t	my_printf_putulnbr_base(uint64_t nb, char *base)
{
  unsigned int	base_n;
  unsigned int	cpt_chars;

  if (!base || my_strlen(base) == 0)
    return (0);
  cpt_chars = 0;
  base_n = my_strlen(base);
  if (nb > base_n - 1)
    {
      cpt_chars += my_printf_putulnbr_base(nb / base_n, base);
    }
  my_putchar(base[nb % base_n]);
  return (cpt_chars + 1);
}

int	my_printf_showstr_oct(char *str)
{
  int	cpt;

  if (str == NULL)
    return (0);
  cpt = 0;
  while (*str != '\0')
    {
      if (!my_is_printable(*str))
	{
	  cpt += my_printf_putchar('\\');
	  if (*str < 0100)
	    cpt += my_printf_putchar('0');
	  if (*str < 010)
	    cpt += my_printf_putchar('0');
	  cpt += my_printf_putulnbr_base(*str, "01234567");
	}
      else
	{
	  cpt += my_printf_putchar(*str);
	}
      str = str + 1;
    }
  return (cpt);
}
