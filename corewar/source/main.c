/*
** main.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/asm/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Feb 23 15:02:59 2016 Quentin Bazin
** Last update Thu Feb 25 17:31:31 2016 Jakob Kellendonk
*/

#include "application.h"

int		main(int argc, char **argv)
{
  t_application	app;

  return (application_init(&app, argc, argv)
	  || application_run(&app)
	  || application_free(&app));
}
