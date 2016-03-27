/*
** lex_register.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar  1 18:29:41 2016 Benjamin Grange
** Last update Tue Mar  1 20:28:55 2016 Benjamin Grange
*/

#include "lexer.h"

t_result	create_result_from_register_token(t_file_reader *file,
						  t_position pos,
						  int regist)
{
  t_token	token;

  token = create_token(file, pos, TOKEN_TYPE_REGISTER);
  token.content.int_value = regist;
  return (create_result_from_token(token));
}

t_result		lex_register(t_file_reader *reader,
				     t_position begin,
				     char *string)
{
  int			nb;

  if (*string == 'r' && my_isnum(string + 1))
    {
      nb = my_getnbr(string + 1);
      if (nb <= 0 || nb > REG_NUMBER)
	{
	  return (create_result_from_se(begin,
					"Register value is out of range"));
	}
      return (create_result_from_register_token(reader, begin, nb));

    }
  return (get_null_result());
}
