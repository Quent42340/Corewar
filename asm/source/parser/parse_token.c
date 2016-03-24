/*
** parse_token.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Mar 23 01:16:54 2016 Benjamin Grange
** Last update Wed Mar 23 23:19:52 2016 Benjamin Grange
*/

#include "parser.h"
#include "lexer.h"

t_parseres			parse_unknown(t_parser *parser,
					      t_token *token)
{
  (void)parser;
  return (get_se_rest(token, "Unexpected token"));
}

void				update_flags(t_parser *parser)
{
  if (!parser->name_actually_defined && parser->name_just_defined)
    parser->name_just_defined = false;
  if (parser->name_actually_defined)
    parser->name_actually_defined = false;
  parser->is_empty = false;
}

t_parseres			parse_all_token(t_parser *parser,
						t_token *token)
{
  int				i;
  ParserFunc			func[TOKEN_TYPE_COUNT];
  t_parseres			res;

  i = (-1);
  while (++i < TOKEN_TYPE_COUNT)
    func[i] = parse_unknown;
  func[TOKEN_TYPE_CONFIG] = parse_config;
  func[TOKEN_TYPE_INSTRUCTION] = parse_instruction;
  res = func[token->type](parser, token);
  update_flags(parser);
  return (res);
}
