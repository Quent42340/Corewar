/*
** program.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/source/core
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 23 12:16:07 2016 Quentin Bazin
** Last update Sun Mar 27 21:21:39 2016 Jakob Kellendonk
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
  while (application->programs + i != program)
    {
      if (((application->programs[i].processes[0].pc - list->address)
	   % MEM_SIZE + MEM_SIZE) % MEM_SIZE < program->info.prog_size
	  || ((list->address - application->programs[i].processes[0].pc)
	      + MEM_SIZE) % MEM_SIZE
	  < application->programs[i].info.prog_size)
	return (print_error(ERROR_OVERLAP));
      i = i + 1;
    }
  return (0);
}

t_err		read_until(unsigned char *target, int fd,
			   int size, char *file_name)
{
  int		r;
  int		total;

  total = 0;
  while (total < size
	 && (r = read(fd, target + total, size - total)) > 0)
    total = total + r;
  if (total != size)
    return (print_error(ERROR_NOT_EXECUTABLE, file_name));
  if (r == -1)
    return (print_error(ERROR_FILE_NOT_ACCESSIBLE, file_name));
  return (0);
}


t_err		put_program_in_vm(t_application *app,
				  t_program *program,
				  t_info_list *list, int fd)
{
  t_err		error;

  if (list->address + program->info.prog_size > MEM_SIZE)
    {
      if ((error = read_until(app->memory + list->address, fd,
			      MEM_SIZE - list->address, list->file_name))
	  || ((error = read_until(app->memory, fd, list->address
				  + program->info.prog_size - MEM_SIZE,
				  list->file_name))))
	return (error);
      if (app->st_callback)
	app->st_callback(app, program, list->address,
			 MEM_SIZE - list->address);
      if (app->st_callback)
	app->st_callback(app, program, 0, list->address
			   + program->info.prog_size - MEM_SIZE);
    }
  else if (read_until(app->memory + list->address, fd,
		      program->info.prog_size, list->file_name))
    return (error);
  else if (app->st_callback)
    app->st_callback(app, program, 0, program->info.prog_size);
  if (read(fd, &error, 1))
    return (print_error(ERROR_NOT_EXECUTABLE, list->file_name));
  return (0);
}

t_err		add_process(t_program *program, t_info_list *list)
{
  if ((program->processes = malloc(sizeof(t_process))) == NULL)
    return (print_error(ERROR_MALLOC_FAILED));
  program->processes[0].carry = 0;
  program->processes[0].cycles_left = 0;
  program->processes[0].pc = list->address;
  program->processes[0].parent = program;
  my_memset(program->processes[0].cmd, 0 , CMD_MAX_SIZE);
  my_memset(program->processes[0].registre[0], 0,
	    sizeof(unsigned char) * REG_NUMBER * REG_SIZE);
  int_to_char(program->live, program->processes[0].registre[0]);
  return (0);
}

t_err		program_init(t_program *program, t_application *app,
			     t_info_list *list)
{
  int		fd;
  t_err		error;

  if ((fd = open(list->file_name, O_RDONLY)) == -1)
    return (print_error(ERROR_OPEN_FAILED, list->file_name));
  if ((error = read_int(fd, &program->info.magic, list->file_name))
      || (error = read_char(fd, program->info.prog_name, PROG_NAME_LENGTH + 4,
			    list->file_name))
      || (error = read_int(fd, &program->info.prog_size, list->file_name))
      || (error = read_char(fd, program->info.comment, COMMENT_LENGTH + 4,
			    list->file_name)))
    return (error);
  program->live = list->live_code;
  program->process_amount = 1;
  program->did_live = 0;
  program->last_live_cycle = 0;
  program->is_alive = 1;
  if ((error = add_process(program, list))
      || (error = put_program_in_vm(app, program, list, fd)))
    return (error);
  close(fd);
  return (0);
}
