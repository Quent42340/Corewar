/*
** token.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 17:18:32 2016 Benjamin Grange
** Last update Tue Feb 23 22:10:21 2016 Benjamin Grange
*/

#ifndef TOKEN_H_
# define TOKEN_H_

# include "position.h"

typedef enum			e_asm_token_type
{
  asm_token_type_instruction,
  asm_token_type_register,
  asm_token_type_direct_value,
  asm_token_type_indirect_value,
  asm_token_type_label,
  asm_token_type_keyword,
  asm_token_type_separator,
  asm_token_type_comment
}				t_asm_token_type;

typedef union			u_asm_token_content
{
  char				*string_value;
  int				int_value;
}				t_asm_token_content;

typedef struct			s_asm_token
{
  t_asm_position		begin;
  t_asm_position		end;
  char				*content_string;
  t_asm_token_content		content;
}				t_asm_token;

typedef struct			s_asm_token_list
{
  t_asm_token			token;
  struct s_asm_token_list	*next;
}				t_asm_token_list;

#endif /* !TOKEN_H_ */
