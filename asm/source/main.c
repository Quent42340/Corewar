/*
** main.c for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/asm/source
**
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
**
** Started on  Tue Feb 23 15:02:59 2016 Quentin Bazin
** Last update Mon Mar 21 15:07:16 2016 Benjamin Grange
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
    {
      my_putstr("Usage: ");
      my_putstr(argv[0]);
      my_putstr(" file_name[.s] ....\n");
    }
  return (0);
}
