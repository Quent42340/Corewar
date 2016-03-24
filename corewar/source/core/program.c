/*
** program.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/source/core
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 23 12:16:07 2016 Quentin Bazin
** Last update Thu Mar 24 22:11:12 2016 Jakob Kellendonk
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "application.h"
#include "my_mem.h"
#include "read_helper.h"

t_err		add_process(t_program *program, t_info_list *list)
{
  int		y;

  if ((program->processes = malloc(sizeof(t_process))) == NULL)
    return (print_error(ERROR_MALLOC_FAILED));
  program->processes[0].carry = 0;
  program->processes[0].pc = list->address;
  y = 0;
  while (y < REG_SIZE)
    {
      my_memset(program->processes[0].registre[y], 0,
		sizeof(unsigned char) * REG_NUMBER);
      ++y;
    }
  my_memcpy(program->processes[0].registre, program->live, 4);
  return (0);
}

t_err		program_init(t_program *program, t_application *app,
			     t_info_list *list)
{
  int		fd;
  t_err		error;

  (void)app;
  if ((fd = open(list->file_name, O_RDONLY)) == -1)
    return (print_error(ERROR_OPEN_FAILED, list->file_name));
  if ((error = read_int(fd, &program->info.magic, list->file_name))
      || (error = read_char(fd, program->info.prog_name, PROG_NAME_LENGTH + 4,
			    list->file_name))
      || (error = read_int(fd, &program->info.prog_size, list->file_name))
      || (error = read_char(fd, program->info.comment, COMMENT_LENGTH + 4,
			    list->file_name)))
    return (error);
  close(fd);
  my_memset(program->live, 0, 4);
  program->live[3] = list->live_code;
  program->process_amount = 1;
  return (add_process(program, list));
}
