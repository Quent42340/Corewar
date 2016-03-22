/*
** application.h for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Feb 23 15:03:45 2016 Quentin Bazin
** Last update Tue Mar  1 17:13:50 2016 Jakob Kellendonk
*/

#ifndef APPLICATION_H_
# define APPLICATION_H_

# include <unistd.h>
# include <stdlib.h>
# include "op.h"

typedef struct		s_info_list
{
  int			live_code;
  int			address;
  char			*file_name;
  struct s_info_list	*next;
}			t_info_list;

typedef struct	s_application
{
  int		cycle_to_die;
  int		cycle_delta;
  int		nbr_live;
  int		dump_cycle;
  t_info_list	*program_list;
}		t_application;

int	application_init(t_application *app, int argc, char **argv);
int	application_run(t_application *app);
int	application_free(t_application *app);

#endif /* !APPLICATION_H_ */
