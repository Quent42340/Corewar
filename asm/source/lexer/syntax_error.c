/*
** syntax_error.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 15:05:31 2016 Benjamin Grange
** Last update Thu Feb 25 15:52:58 2016 Benjamin Grange
*/

#include "lexer.h"

void		*print_syntax_error(void *r)
{
  t_result	*result;

  result = (t_result *)r;
  if (result != NULL)
    {
      my_puterror(RED);
      my_puterror("Error ligne ");
      my_putnbr_error(result->syntax_error.position.line);
      my_puterror(" colonne ");
      my_putnbr_error(result->syntax_error.position.column);
      my_puterror(" : ");
      my_puterror(result->syntax_error.error);
      my_puterror(WHITE);
      my_putchar_error('\n');
    }
  return (NULL);
}
