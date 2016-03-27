/*
** lex_instruction.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar  1 16:37:01 2016 Benjamin Grange
** Last update Tue Mar  1 17:26:46 2016 Benjamin Grange
*/

#include "lexer.h"
#include "instruction.h"

t_result	create_result_from_instru_token(t_file_reader *file,
						t_position pos,
						t_instruction_type inst)
{
  t_token	token;

  token = create_token(file, pos, TOKEN_TYPE_INSTRUCTION);
  token.content.instruction = inst;
  return (create_result_from_token(token));
}

t_result		lex_instruction(t_file_reader *reader,
					t_position begin,
					char *string)
{
  int			i;

  i = 0;
  while (op_tab[i].mnemonique != NULL)
    {
      if (my_strcmp(string, op_tab[i].mnemonique))
	return (create_result_from_instru_token(reader,
						begin,
						op_tab[i].code));
      i++;
    }
  return (get_null_result());
}
