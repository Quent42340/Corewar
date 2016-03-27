/*
** syntax_printer.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/asm/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Mar 22 23:02:42 2016 Benjamin Grange
** Last update Tue Mar 22 23:10:11 2016 Benjamin Grange
*/

#include "syntax_error.h"

void				print_line_from_pos(t_file_reader *file,
						    t_position pos,
						    int *begin)
{
  while (pos.column > 0 && pos.index > 0)
    {
      pos.column--;
      pos.index--;
    }
  if (begin)
    *begin = pos.index;
  while (file->file->content[pos.index]
	 && file->file->content[pos.index] != '\n')
    {
      my_putchar_error(file->file->content[pos.index]);
      pos.index++;
    }
  my_putchar_error('\n');
}

void				print_line_spaces(t_file_reader *file,
						  int begin,
						  int column)
{
  int				i;

  i = 0;
  while (i++ < column)
    my_putchar_error(file->file->content[begin + i - 1] == '\t' ? '\t' : ' ');
}
