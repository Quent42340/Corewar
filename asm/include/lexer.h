/*
** lexer.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:32:19 2016 Benjamin Grange
** Last update Mon Feb 29 16:02:46 2016 Benjamin Grange
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

typedef t_result	(*LexerFunction)(t_file_reader *);

/*
** Lexing functions
*/
t_token_list	*lexer(t_program_file *);
t_result	lex_token(t_file_reader *);
t_result	lex_config(t_file_reader *);
t_result	lex_string(t_file_reader *);

/*
** Result functions
*/
t_result	create_result_from_token(t_token);
t_result	create_result_from_se(t_position, char *);
t_result	create_result_from_int_token(t_file_reader *, t_position, int);
t_result	create_result_from_op_token(t_file_reader *file, t_position,
					    t_operator_enum);
t_result	create_result_from_config_token(t_file_reader *, t_position,
						t_config_enum);
t_result	create_result_from_string_token(t_file_reader *, t_position);
t_result	get_null_result();

#endif /* !LEXER_H_ */
