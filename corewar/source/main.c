/*
** main.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/asm/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Feb 23 15:02:59 2016 Quentin Bazin
** Last update Tue Feb 23 15:02:59 2016 Quentin Bazin
*/

#include "application.h"

int		main(int argc, char **argv)
{
  t_application	app;

  application_init(&app, argc, argv);
  application_run(&app);
  application_free(&app);
  return (0);
}
