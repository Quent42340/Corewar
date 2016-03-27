/*
** syntax_warning.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/asm/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar 22 22:57:22 2016 Benjamin Grange
** Last update Wed Mar 23 00:43:19 2016 Benjamin Grange
*/

#include "syntax_error.h"
#include "parser.h"

void			print_warning(t_file_reader *fr, t_token *token)
{
  int			column;
  int			begin;

  column = token->begin.column;
  print_line_from_pos(fr, token->begin, &begin);
  print_line_spaces(fr, begin, column);
  my_puterror(GREEN);
  while (column < token->end.column)
    {
      my_putchar_error('~');
      column++;
    }
  my_puterror(WHITE);
  my_putchar_error('\n');
}

void			print_warning_msg(char *err,
					  t_bool have_pos,
					  t_position pos)
{
  if (err != NULL)
    {
      my_puterror(YELLOW"Warning");
      if (have_pos)
	{
	  my_putstr(" (line ");
	  my_putnbr_error(pos.line + 1);
	  my_puterror(", column ");
	  my_putnbr_error(pos.column);
	  my_puterror(")");
	}
      my_puterror(" : ");
      my_puterror(err);
      my_puterror(WHITE);
      my_putchar_error('\n');
    }
}

void			raise_warning(void *parser,
				      t_token_list *tokenl, char *err)
{
  raise_warning_t(parser, tokenl != NULL ? &tokenl->token : NULL, err);
}

void			raise_warning_t(void *parser,
					t_token *t, char *err)
{

  print_warning_msg(err, t != NULL, t != NULL ? t->begin : (t_position){0});
  if (t != NULL)
    print_warning(((t_parser *)parser)->reader, t);
}
