/*
** messages.c for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/source/run
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Sat Mar 26 17:07:12 2016 Flora Huot
** Last update Sat Mar 26 17:07:12 2016 Flora Huot
*/

#include <my_printf.h>
#include "application.h"

void	message_alive(t_program *program, int player)
{
  char	*prog_name;

  prog_name = program->info.prog_name;
  my_printf("Le joueur %d (%s) est en vie !\n", player, prog_name);
}

void	message_win(t_program *program, int player)
{
  char	*prog_name;

  prog_name = program->info.prog_name;
  my_printf("Le joueur %d (%s) a gagné !\n", player, prog_name);
}
