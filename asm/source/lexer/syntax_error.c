/*
** syntax_error.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 15:05:31 2016 Benjamin Grange
** Last update Mon Feb 29 21:21:06 2016 Benjamin Grange
*/

#include "lexer.h"

void		print_line_error_at_coord(t_file_reader *file,
					  t_position pos)
{
  int		i;
  unsigned int	save;

  while (pos.column > 0 && pos.index > 0)
    {
      pos.column--;
      pos.index--;
    }
  save = pos.index;
  while (file->file->content[pos.index]
	 && file->file->content[pos.index] != '\n')
    {
      my_putchar_error(file->file->content[pos.index]);
      pos.index++;
      pos.column++;
    }
  my_putchar_error('\n');
  i = 0;
  while (i++ < pos.column)
    my_putchar_error(file->file->content[save + i - 1] == '\t' ? '\t' : ' ');
  my_puterror(GREEN);
  my_putchar_error('^');
  my_puterror(WHITE);
  my_putchar_error('\n');
}

void		*print_syntax_error(t_file_reader *file, void *r)
{
  t_result	*result;

  result = (t_result *)r;
  if (result != NULL)
    {
      my_puterror(RED);
      my_puterror("Syntax Error at (line ");
      my_putnbr_error(result->syntax_error.position.line + 1);
      my_puterror(", column ");
      my_putnbr_error(result->syntax_error.position.column);
      my_puterror(") : ");
      my_puterror(result->syntax_error.error);
      my_puterror(WHITE);
      my_putchar_error('\n');
      print_line_error_at_coord(file, result->syntax_error.position);
    }
  return (NULL);
}

t_syntax_error		generate_syntax_error(t_position pos, char *str)
{
  t_syntax_error	error;

  error.position = pos;
  error.error = str;
  return (error);
}
