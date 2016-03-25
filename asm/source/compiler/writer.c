/*
** writer.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/compiler/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 15:37:24 2016 Benjamin Grange
** Last update Fri Mar 25 18:09:30 2016 Benjamin Grange
*/

#include "compiler.h"

void			write_params(t_operation *op, int fd)
{
  size_t		i;
  int			res;

  i = 0;
  while (i < op->nb_params)
    {
      res = 0;
      if (i < op->nb_params)
	res = (res << 2) + op->params_type[i];
      if (i + 1 < op->nb_params)
	res = (res << 2) + op->params_type[i + 1];
      if (i + 2 < op->nb_params)
	res = (res << 2) + op->params_type[i + 2];
      if (i + 3 < op->nb_params)
	res = (res << 2) + op->params_type[i + 3];
      write(fd, &res, 4);
      i += 4;
    }
}

void			write_instruction(t_operation *op, int fd)
{
  size_t		i;

  i = 0;
  while (i < op->nb_params)
    {
      write(fd, &op->params_value[i],
	    get_param_size(op->op, op->params_type[i], i));
      i++;
    }
}

void			write_program(t_program *program)
{
  int			fd;
  t_operation		*op;

  if (program->is_valid)
    {
      fd = open_file(get_program_name(program->file_name));
      if (fd > 0)
	{
	  write(fd, &program->header, sizeof(t_header));
	  op = program->op;
	  while (op)
	    {
	      write(fd, &op->op, 1);
	      write_params(op, fd);
	      write_instruction(op, fd);
	      op = op->next;
	    }
	}
    }
}
