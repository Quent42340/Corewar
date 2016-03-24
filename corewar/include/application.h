/*
** application.h for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Feb 23 15:03:45 2016 Quentin Bazin
** Last update Thu Mar 24 13:22:35 2016 Jakob Kellendonk
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
  int			live_amount;
  int			program_amount;
  t_constants		*constants;
}			t_application;

t_err	application_init(t_application *app, t_args *args);
t_err	application_run(t_application *app);
void	application_free(t_application *app);

#endif /* !APPLICATION_H_ */
