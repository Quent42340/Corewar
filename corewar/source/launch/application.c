/*
** application.c for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Tue Mar 22 17:04:58 2016 Jakob Kellendonk
** Last update Tue Mar 22 18:43:58 2016 Jakob Kellendonk
*/

#include "application.h"
#include "champions.h"
#include "my_mem.h"

t_err		init_program(t_application *application, t_program *program,
			     t_info_list *list)
{
  int		fd;

  (void)application;
  fd = open(list->file_name, O_RDONLY);
  if (fd == - 1)
    return (print_error(ERROR_OPEN_FAILED, list->file_name));
  read_int(fd, &program->info.magic);
  lseek(fd, PROG_NAME_LENGTH + 4 + 4, SEEK_CUR);
  close(fd);
  return (0);
}

t_err		application_init(t_application *application, t_args *args)
{
  int		i;
  t_err		error;
  t_info_list	*list;

  application->constants = args->constants;
  application->cycle_to_die = args->cycle_to_die;
  application->programs = malloc(sizeof(t_program) * args->program_amount);
  if (application->programs == NULL)
    return (print_error(ERROR_MALLOC_FAILED, NULL));
  application->program_amount = args->program_amount;
  i = 0;
  list = args->program_list;
  while (i < application->program_amount)
    {
      if ((error = init_program(application, application->programs + i, list)))
	return (error);
      list = list->next;
      i = i + 1;
    }
  return (0);
}

void	application_run(t_application *application)
{
  (void)application;
  /* TODO : app run */
}

void	application_free(t_application *application)
{
  (void)application;
  /* TODO : app free */
}
