/*
** parse_label_address.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 02:10:17 2016 Benjamin Grange
** Last update Fri Mar 25 17:55:28 2016 Benjamin Grange
*/

#include "parser.h"
#include "compiler.h"

size_t				param_size(t_token *instruction,
					   t_token_list **params, int i)
{
  t_token_list			*param;

  param = *params;
  if (param->token.type == TOKEN_TYPE_REGISTER)
    return (get_param_size(instruction->content.instruction, T_REG, i));
  else if (param->token.type == TOKEN_TYPE_OPERATOR
	   && param->token.content.operator == OPERATOR_DIRECT)
    {
      *params = (*params)->next;
      return (get_param_size(instruction->content.instruction, T_DIR, i));
    }
  else if (param->token.type == TOKEN_TYPE_INTEGER
	   || param->token.type == TOKEN_TYPE_DIRECT_LABEL)
    return (get_param_size(instruction->content.instruction, T_IND, i));
  return (0);
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
      *address += 1 + write_instruction_parameters(&token->token);
      op = op_tab[token->token.content.instruction - 1];
      i = 0;
      param = token->next;
      while (param && param->token.type == TOKEN_TYPE_WHITESPACE)
	param_next(&param);
      while (i < op.nbr_args && param)
	{
	  *address += param_size(&token->token, &param, i);
	  param_next(&param);
	  while (param && (param->token.type == TOKEN_TYPE_WHITESPACE
		 || (param->token.type == TOKEN_TYPE_OPERATOR
		     && param->token.content.operator == OPERATOR_COMMA)))
	    param_next(&param);
	  i++;
	}
    }
}
