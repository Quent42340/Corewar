/*
** program.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/source/core
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 23 12:16:07 2016 Quentin Bazin
** Last update Wed Mar 23 12:16:07 2016 Quentin Bazin
*/

#include "application.h"
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
  int		i;
  int		fd;
  t_err		error[4];

  (void)app;
  fd = open(list->file_name, O_RDONLY);
  if (fd == -1)
    return (print_error(ERROR_OPEN_FAILED, list->file_name));
  error[0] = read_int(fd, &program->info.magic, list->file_name);
  error[1] = read_char(fd, program->info.prog_name,
	    PROG_NAME_LENGTH + 4, list->file_name);
  error[2] = read_int(fd, &program->info.prog_size, list->file_name);
  error[3] = read_char(fd, program->info.comment,
		       COMMENT_LENGTH + 4, list->file_name);
  i = 0;
  while (i < 4 && !error[i])
    ++i;
  if (i < 4)
    return (error[i]);
  close(fd);
  my_memset(program->live, 0, 4);
  program->live[3] = list->live_code;
  program->process_amount = 1;
  if (error[0] = add_process(program, list))
    return (error[0]);
  return (0);
}
