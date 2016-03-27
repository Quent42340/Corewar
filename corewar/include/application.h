/*
** application.h for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Feb 23 15:03:45 2016 Quentin Bazin
** Last update Sun Mar 27 21:23:16 2016 Jakob Kellendonk
*/

#ifndef APPLICATION_H_
# define APPLICATION_H_

# include "program.h"

typedef struct		s_application
{
  unsigned char		memory[MEM_SIZE];
  t_program		*programs;
  int			cycle_to_die;
  int			cycle;
  int			last_limit_hit;
  int			live_count;
  int			live_amount;
  int			program_amount;
  void			(*death_callback)(struct s_application *, t_program *);
  void			(*st_callback)(struct s_application *, t_program *,
				       int index, int size);
  t_constants		*constants;
  void			*qt_data;
}			t_application;

t_err	application_init(t_application *app, t_args *args);
t_err	application_run(t_application *app);
void	application_free(t_application *app);

#endif /* !APPLICATION_H_ */
