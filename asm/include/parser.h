/*
** parser.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 23:32:58 2016 Benjamin Grange
** Last update Fri Mar 25 22:42:47 2016 Benjamin Grange
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "asm.h"
# include "token.h"
# include "program.h"
# include "syntax_error.h"

typedef enum		e_parseres
{
  RESULT_PARSE_INSTRUCTION,
  RESULT_PARSE_ERROR
}			t_parseres_type;

typedef struct		s_parseres
{
  t_parseres_type	type;
  t_syntax_error	syntax_error;
}			t_parseres;

typedef struct		s_labelr
{
  char			*name;
  size_t		cur_pc;
  int			type;
  t_content		*content;
}			t_labelr;

typedef struct		s_label
{
  char			*name;
  size_t		address;
  struct s_label	*next;
}			t_label;

typedef struct		s_parser
{
  t_bool		is_empty;
  t_labelr		*labelr;
  t_label		*label;
  t_bool		name_defined;
  t_bool		name_actually_defined;
  t_bool		name_just_defined;
  t_bool		comment_defined;
  t_file_reader		*reader;
  t_program		program;
  t_token_list		*tokenlist;
  t_token_list		*tkn;
}			t_parser;

typedef t_parseres	(*ParserFunc)(t_parser *, t_token *);

/* Basic parser functions */

t_program		parser(t_token_list *, t_program_file *, t_bool);
void			delete_all_comments(t_token_list **);
t_bool			has_next_token(t_parser *);
t_token			*get_next_token(t_parser *);
t_parseres		get_instruction_result(void);
t_parseres		get_se_res(t_token_list *t, char *error);
t_parseres		get_se_rest(t_token *t, char *error);
t_parseres		get_whitespace_error(t_token *);
t_bool			verify_EOL(t_parser *parser);
void			raise_final_warnings_errors(t_parser *parser);

/* Parsing functions */

t_parseres		parse_label(t_parser *, t_token *);
t_parseres		parse_all_token(t_parser *, t_token *);
t_bool			parse_whitespace(t_parser *);
t_parseres		parse_config(t_parser *, t_token *token);
t_parseres		parse_instruction(t_parser *, t_token *);
t_parseres		parse_arguments(t_parser *, t_token *,
					t_operation *, t_args_type);
t_parseres		parse_register(t_token *, t_operation *);
t_parseres		parse_direct_value(t_parser *, t_token *,
					   t_operation *);
t_parseres		parse_indirect_value(t_parser *, t_token *,
					     t_operation *);

#endif /* !PARSER_H_ */
