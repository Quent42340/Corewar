/*
** writer.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/compiler/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Mar 25 18:51:48 2016 Benjamin Grange
** Last update Sat Mar 26 21:42:30 2016 Benjamin Grange
*/

#include "compiler.h"

void			write_int(int fd, int nb)
{
  unsigned int		a;
  unsigned char		str[4];

  if (nb < 0)
    a = ~(unsigned int)((nb + (nb < 0)) * ((nb > 0) * 2 - 1));
  else
    a = nb;
  str[0] = (a >> 24u);
  str[1] = (a >> 16u) & 255u;
  str[2] = (a >> 8u) & 255u;
  str[3] = (a & 255u);
  /*
  printf("[%#x ", str[0]);
  printf("%#x ", str[1]);
  printf("%#x ", str[2]);
  printf("%#x] ", str[3]);
  */
  write(fd, &str[0], sizeof(unsigned char));
  write(fd, &str[1], sizeof(unsigned char));
  write(fd, &str[2], sizeof(unsigned char));
  write(fd, &str[3], sizeof(unsigned char));
}

void			write_short(int fd, short nb)
{
  unsigned char		str[2];
  unsigned int		a;

  if (nb < 0)
    a = ~(unsigned int)((nb + (nb < 0)) * ((nb > 0) * 2 - 1));
  else
    a = nb;
  str[0] = (a >> 8u) & 255u;
  str[1] = (a & 255u);
  /*
  printf("[%#x ", str[0]);
  printf("%#x] ", str[1]);
  */
  write(fd, &str[0], sizeof(unsigned char));
  write(fd, &str[1], sizeof(unsigned char));
}

void			write_operation(t_operation *op, int fd)
{
  size_t		i;

  // printf("[%#x] ", (char)op->op_num);
  write(fd, &op->op_num, 1);
  if (write_instruction_parameters(op->op_num))
    {
      // printf("[%#x] ", (char)op->param_type);
      write(fd, &op->param_type, 1);
    }
  i = 0;
  while (i < op->nb_param)
    {
      if (op->param_size[i] == 0)
	{
	//   printf("[%#x] ", (char)op->param_content[i].reg);
	  write(fd, &op->param_content[i].reg, sizeof(char));
	}
      else if (op->param_size[i] == 1 || op->param_size[i] == 2)
	write_short(fd, op->param_content[i].indirect);
      else if (op->param_size[i] == 3)
	write_int(fd, op->param_content[i].direct);
      i++;
    }
  // printf("\n");
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
	  set_program_magic(program);
	  set_program_size(program);
	  write(fd, &program->header, sizeof(t_header));
	  op = program->op;
	  while (op)
	    {
	      write_operation(op, fd);
	      op = op->next;
	    }
	  close(fd);
	}
    }
}
