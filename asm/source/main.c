/*
** main.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/asm/source
**
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
**
** Started on  Tue Feb 23 15:02:59 2016 Quentin Bazin
** Last update Wed Feb 24 01:03:54 2016 Benjamin Grange
*/

#include "asm.h"

int		main(int argc, char *argv[])
{
  if (argc >= 2)
    {
      argv++;
      while (*argv)
	compile_file(*(argv++));
    }
  else
    my_putstr("Usage: ./asm file_name[.s] ....\n");
  return (0);
}
