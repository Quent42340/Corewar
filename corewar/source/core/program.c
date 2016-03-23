/*
** program.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/source/launch
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 23 12:16:07 2016 Quentin Bazin
** Last update Wed Mar 23 12:16:07 2016 Quentin Bazin
*/

#include "application.h"
#include "champions.h"

t_err		program_init(t_program *program, t_application *app,
			     t_info_list *list)
{
  int		fd;

  (void)app;
  fd = open(list->file_name, O_RDONLY);
  if (fd == -1)
    return (print_error(ERROR_OPEN_FAILED, list->file_name));
  read_int(fd, &program->info.magic);
  lseek(fd, PROG_NAME_LENGTH + 4 + 4, SEEK_CUR);
  close(fd);
  return (0);
}
