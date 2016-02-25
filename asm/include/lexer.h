/*
** lexer.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:32:19 2016 Benjamin Grange
** Last update Thu Feb 25 16:03:31 2016 Benjamin Grange
*/

#ifndef LEXER_H_
# define LEXER_H_

# include "asm.h"
# include "operator.h"
# include "syntax_error.h"

typedef enum		e_result_type
{
  RESULT_TOKEN,
  RESULT_NULL,
  RESULT_ERROR
}			t_result_type;

typedef struct		s_result
{
  t_result_type		type;
  t_token		token;
  t_syntax_error	syntax_error;
}			t_result;

t_token_list	*lexer(t_program_file *);
t_result	lex_token(t_file_reader *);

#endif /* !LEXER_H_ */
