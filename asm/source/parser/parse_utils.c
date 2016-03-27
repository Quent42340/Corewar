/*
** parse_utils.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 15:40:14 2016 Benjamin Grange
** Last update Sun Mar 27 16:21:47 2016 Benjamin Grange
*/

#include "parser.h"

t_bool			verify_EOL(t_parser *parser)
{
  t_token		*tkn;

  parse_whitespace(parser);
  if (has_next_token(parser))
    {
      tkn = get_next_token(parser);
      if (tkn->type != TOKEN_TYPE_EOL)
	{
	  generate_and_print_se(parser->reader, tkn->begin,
				"One instruction per line only :/");
	  return (true);
	}
      return (false);
    }
  return (false);
}

void			raise_final_warnings_errors(t_parser *parser)
{
  if (parser->is_empty && parser->program.is_valid)
    {
      generate_and_print_se(parser->reader, (t_position){0},
			    "File is empty");
      parser->program.is_valid = false;
    }
  else if (parser->program.is_valid)
    {
      if (!parser->name_defined)
	{
          generate_and_print_se(parser->reader, (t_position){0},
				"No name specified");
	  parser->program.is_valid = false;
	}
      if (!parser->comment_defined)
	raise_warning(&parser, NULL, "No comment specified");
    }
}
