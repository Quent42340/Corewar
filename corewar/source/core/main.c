/*
** main.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/asm/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Feb 23 15:02:59 2016 Quentin Bazin
** Last update Fri Mar 25 17:07:05 2016 Jakob Kellendonk
*/

#include "application.h"

int		main(int argc, char **argv)
{
  t_application	app;
  t_args	args;

  if (!args_init(&args, argc, argv) && !application_init(&app, &args))
    {
      args_free(&args);
      application_run(&app);
    }
  application_free(&app);
  return (0);
}
