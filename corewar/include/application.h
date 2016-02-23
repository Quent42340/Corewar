/*
** application.h for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Feb 23 15:03:45 2016 Quentin Bazin
** Last update Tue Feb 23 15:03:45 2016 Quentin Bazin
*/
#ifndef APPLICATION_H_
# define APPLICATION_H_

typedef struct	s_application
{
  int		argc;
  char		**argv;
}		t_application;

void	application_init(t_application *app, int argc, char **argv);
void	application_run(t_application *app);
void	application_free(t_application *app);

#endif /* !APPLICATION_H_ */
