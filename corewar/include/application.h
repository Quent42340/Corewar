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
# include "error.h"
# include "my.h"
# include "op.h"

typedef struct		s_constants
{
  int			cycle_delta;
  int			nbr_live;
  int			dump_cycle;
}			t_constants;

typedef struct		s_info_list
{
  int			live_code;
  int			address;
  char			*file_name;
  struct s_info_list	*next;
}			t_info_list;

typedef struct		s_args
{
  int			cycle_to_die;
  t_constants		*constants;
  t_info_list		*program_list;
  int			program_amount;
}			t_args;

typedef struct		s_process
{
  int			cycles_left;
  int			carry;
  int			pc;
  unsigned char		registre[REG_SIZE][REG_NUMBER];
}			t_process;

typedef struct		s_program
{
  struct header_s	info;
  int			live;
  t_process		*processes;
  int			did_live;
}			t_program;

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

int	args_init(t_args *args, int argc, char **argv);
int	args_free(t_args *args);
t_err	application_init(t_application *app, t_args *args);
void	application_run(t_application *app);
void	application_free(t_application *app);

#endif /* !APPLICATION_H_ */
