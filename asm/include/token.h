/*
** token.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 17:18:32 2016 Benjamin Grange
** Last update Mon Mar 21 15:46:03 2016 Benjamin Grange
*/

#ifndef TOKEN_H_
# define TOKEN_H_

# include "instruction.h"
# include "file_reader.h"
# include "position.h"
# include "operator.h"
# include "config.h"

typedef enum			e_token_type
{
  TOKEN_TYPE_INSTRUCTION,
  TOKEN_TYPE_REGISTER,
  TOKEN_TYPE_INTEGER,
  TOKEN_TYPE_DIRECT_LABEL,
  TOKEN_TYPE_OPERATOR,
  TOKEN_TYPE_STRING,
  TOKEN_TYPE_CONFIG,
  TOKEN_TYPE_COMMENT,
  TOKEN_TYPE_LABEL,
  TOKEN_TYPE_WHITESPACE,
  TOKEN_TYPE_EOL,
  TOKEN_TYPE_COUNT
}				t_token_type;

typedef union			u_token_content
{
  char				*string_value;
  int				int_value;
  t_operator_enum		operator;
  t_config_enum			config;
  t_instruction_type		instruction;
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

t_token				create_token(t_file_reader *,
					     t_position,
					     t_token_type);
int				add_token_to_list(t_token_list **,
						  t_token);
void				free_token_list(t_token_list *);

#endif /* !TOKEN_H_ */
