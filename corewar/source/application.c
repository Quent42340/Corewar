/*
** application.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Feb 23 15:03:50 2016 Quentin Bazin
** Last update Tue Feb 23 15:03:50 2016 Quentin Bazin
*/

#include "application.h"

void	application_init(t_application *app, int argc, char **argv)
{
  app->argc = argc;
  app->argv = argv;
}

void	application_run(t_application *app)
{
  (void)app;
}

void	application_free(t_application *app)
{
  (void)app;
}
