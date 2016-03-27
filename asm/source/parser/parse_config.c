/*
** parse_config.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/parser/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar 22 12:50:56 2016 Benjamin Grange
** Last update Sat Mar 26 23:27:29 2016 Benjamin Grange
*/

#include "basic.h"
#include "parser.h"
#include "compiler.h"

char			*get_error_msg(char *error, char *name)
{
  char			e[my_strlen(error) + my_strlen(name) + 1];

  my_cpystr(e, error);
  my_strcat(e, name);
  return (my_strdup(e));
}

t_parseres		parse_config_param(t_parser *parser, t_token *t,
					   int i)
{
  t_token		*string;

  if (parse_whitespace(parser))
    return (get_whitespace_error(t));
  if (has_next_token(parser))
    {
      string = get_next_token(parser);
      if (string->type == TOKEN_TYPE_STRING)
	return (set_program_config(parser, string, i));
      else
	return (get_se_rest(string, "Program name is not a string"));
    }
  else
    return (get_se_res(parser->tkn,
		       get_error_msg("Expected program ",
				     i ? "name" : "comment")));
}

t_parseres		parse_config(t_parser *parser, t_token *token)
{
  if (token->content.config == CONFIG_NAME)
    {
      if (parser->name_defined)
	return (get_se_rest(token, "Program name already defined"));
      parser->name_defined = true;
      parser->name_just_defined = true;
      parser->name_actually_defined = true;
      return (parse_config_param(parser, token, 1));
    }
  else if (token->content.config == CONFIG_COMMENT)
    {
      if (parser->comment_defined)
	return (get_se_rest(token, "Program comment already defined"));
      parser->comment_defined = true;
      if (!parser->name_defined || !parser->name_just_defined)
	{
	  return (get_se_rest(token,
			      "Program comment must follow "\
			      "the program name"));
	}
	return (parse_config_param(parser, token, 0));
    }
  else
    return (get_se_res(parser->tkn, "Unexpected config token"));
}
