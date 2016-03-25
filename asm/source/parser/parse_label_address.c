/*
** parse_label_address.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 02:10:17 2016 Benjamin Grange
** Last update Fri Mar 25 03:30:50 2016 Benjamin Grange
*/

#include "parser.h"

t_bool				is_index(t_token *instru, int i)
{
  if (instru->content.instruction == INSTRUCTION_ZJMP
      || (instru->content.instruction == INSTRUCTION_LDI
	  && i >= 0 && i <= 1)
      || (instru->content.instruction == INSTRUCTION_STI
	  && i >= 1 && i <= 2)
      || instru->content.instruction == INSTRUCTION_FORK)
    return (1);
  return (0);
}

size_t				get_param_size(t_token *instruction,
					       t_token_list **params, int i)
{
  t_token_list			*param;

  param = *params;
  if (param->token.type == TOKEN_TYPE_REGISTER)
    return (1);
  else if (param->token.type == TOKEN_TYPE_OPERATOR
	   && param->token.content.operator == OPERATOR_DIRECT)
    {
      *params = (*params)->next;
      if (is_index(instruction, i))
	return (IND_SIZE);
      else
	return (DIR_SIZE);
    }
  else if (param->token.type == TOKEN_TYPE_INTEGER
	   || param->token.type == TOKEN_TYPE_DIRECT_LABEL)
    return (IND_SIZE);
  return (0);
}

t_bool				write_instruction_parameters(t_token *token)
{
  if (token->content.instruction == INSTRUCTION_LIVE
      || token->content.instruction == INSTRUCTION_ZJMP
      || token->content.instruction == INSTRUCTION_FORK
      || token->content.instruction == INSTRUCTION_LFORK)
    return (0);
  return (1);
}

void				param_next(t_token_list **param)
{
  if (*param)
    *param = (*param)->next;
}

void				add_address(t_token_list *token, size_t *address)
{
  t_token_list			*param;
  int				i;
  t_op				op;

  if (token->token.type == TOKEN_TYPE_INSTRUCTION)
    {
      *address += 1;
      if (write_instruction_parameters(&token->token))
	*address += (MAX_ARGS_NUMBER / 4 + !!(MAX_ARGS_NUMBER % 4));
      op = op_tab[token->token.content.instruction - 1];
      i = 0;
      param = token->next;
      while (param && param->token.type == TOKEN_TYPE_WHITESPACE)
	param_next(&param);
      while (i < op.nbr_args && param)
	{
	  *address += get_param_size(&token->token, &param, i);
	  param_next(&param);
	  while (param && (param->token.type == TOKEN_TYPE_WHITESPACE
		 || (param->token.type == TOKEN_TYPE_OPERATOR
		     && param->token.content.operator == OPERATOR_COMMA)))
	    param_next(&param);
	  i++;
	}
    }
}
