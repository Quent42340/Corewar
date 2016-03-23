/*
** application.h for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Feb 23 15:03:45 2016 Quentin Bazin
** Last update Tue Mar 22 17:56:17 2016 Jakob Kellendonk
*/

#ifndef APPLICATION_H_
# define APPLICATION_H_

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "args.h"
# include "error.h"
# include "my.h"
# include "program.h"

typedef struct		s_application
{
  unsigned char		memory[MEM_SIZE];
  t_program		*programs;
  int			cycle_to_die;
  int			cycle;
  int			live_amount;
  int			program_amount;
  t_constants		*constants;
}			t_application;

t_err	application_init(t_application *app, t_args *args);
void	application_run(t_application *app);
void	application_free(t_application *app);

#endif /* !APPLICATION_H_ */
