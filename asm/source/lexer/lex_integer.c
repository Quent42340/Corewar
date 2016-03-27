/*
** lex_integer.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Mar  2 15:53:31 2016 Benjamin Grange
** Last update Wed Mar  2 17:25:55 2016 Benjamin Grange
*/

#include "lexer.h"

t_result		lex_integer(t_file_reader *reader,
				    t_position begin,
				    char *string)
{
  int			nb;

  if (my_isnum(string))
    {
      nb = my_getnbr(string);
      return (create_result_from_int_token(reader, begin, nb));
    }
  return (get_null_result());
}
