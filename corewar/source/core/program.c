/*
** program.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/source/core
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 23 12:16:07 2016 Quentin Bazin
** Last update Sat Mar 26 12:43:36 2016 Jakob Kellendonk
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "application.h"
#include "my_mem.h"
#include "read_helper.h"

t_err		set_address(t_application *application, t_program *program,
			    t_info_list *list)
{
  int		i;

  if (list->address == -1)
    {
      /* FIXME: WTF SHOULD I DO ? */
    }
  i = 0;
  while (application->programs[i] != program)
    {
      if (((application->programs[i].processes[0].pc - list->address)
	   % MEM_SIZE + MEM_SIZE) % MEM_SIZE < program->info.prog_size
	  || ((list->address - application->programs[i].processes[0].pc)
	      + MEM_SIZE) % MEM_SIZE
	  < application->programs[i].info.prog_size)
	return (ERROR_OVERLAP);
      i = i + 1;
    }
  return (0);
}

t_err		read_until(void *target, int fd, int size)
{
  int		r;
  int		total;
  int		i;

  total = 0;
  while ((r = read(fd, target + total, size - total)) > 0)
    total = total + r;
  if (r == 0)
    return (ERROR_NOT_EXECUTABLE);
  if (r == -1)
    return (ERROR_FILE_NOT_ACCESSIBLE);
  i = 0;
  return (0);
}

t_err		put_program_in_vm(t_application *application,
				  t_program *program,
				  t_info_list *list, int fd)
{
  t_err		error;

  if (list->address + program->info->prog_size > MEM_SIZE)
    {
      if (error = read_until(vm->memory + list->address, fd,
			     MEM_SIZE - list->address)
	  || error = read_until(vm->memory, fd, list->address
				+ program->info->prog_size - MEM_SIZE))
	reutnr (error);
      return (0);
    }
  return (read_until(vm->memory + list->address, fd,
		     program->info->prog_size));
}
    
t_err		add_process(t_program *program, t_info_list *list)
{
  if ((program->processes = malloc(sizeof(t_process))) == NULL)
    return (print_error(ERROR_MALLOC_FAILED));
  program->processes[0].carry = 0;
  program->processes[0].pc = list->address;
  program->processes[0].parent = program;
  my_memset(program->processes[0].registre[0], 0,
	    sizeof(unsigned char) * REG_NUMBER * REG_SIZE);
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
  if ((error == add_process(program, list)) || (error = put_program_in_vm(app, program, fd)))
    return (error);
  return (0);
}
