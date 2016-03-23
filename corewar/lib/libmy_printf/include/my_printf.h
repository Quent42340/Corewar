/*
** my_printf.h for  in /blinux_home/bazin_q/rendu/PSU_2015_my_printf/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun Nov 08 17:36:46 2015 Quentin Bazin
** Last update Sun Nov 29 19:23:49 2015 Quentin Bazin
*/
#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

#include <stdarg.h>
#include <stdint.h>

#define FORMATS 4

typedef struct		s_my_format
{
  char			*specifiers;
  int			(*print_func)(va_list *args, char specifier);
}			t_my_format;

int		my_printf(const char *format, ...);

int		my_printf_print_int(va_list *args, char specifier);
int		my_printf_print_uint(va_list *args, char specifier);
int		my_printf_print_chars(va_list *args, char specifier);
int		my_printf_print_ptr_addr(va_list *args, char specifier);

int		my_printf_putchar(char c);
int		my_printf_putstr(char *str);
uint64_t	my_printf_putulnbr_base(uint64_t nb, char *base);
int		my_printf_showstr_oct(char *str);

#endif /* !MY_PRINTF_H_ */
