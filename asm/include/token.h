/*
** token.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 17:18:32 2016 Benjamin Grange
** Last update Wed Feb 24 16:19:51 2016 Benjamin Grange
*/

#ifndef TOKEN_H_
# define TOKEN_H_

# include "position.h"

typedef enum			e_token_type
{
  asm_token_type_instruction,
  asm_token_type_register,
  asm_token_type_direct_value,
  asm_token_type_integer,
  asm_token_type_label,
  asm_token_type_identifier,
  asm_token_type_separator,
  asm_token_type_string,
  asm_token_type_comment
}				t_token_type;

typedef union			u_token_content
{
  char				*string_value;
  int				int_value;
}				t_token_content;

typedef struct			s_token
{
  t_position			begin;
  t_position			end;
  char				*content_string;
  t_token_type			type;
  t_token_content		content;
}				t_token;

typedef struct			s_token_list
{
  t_token			token;
  struct s_token_list		*next;
}				t_token_list;

#endif /* !TOKEN_H_ */
