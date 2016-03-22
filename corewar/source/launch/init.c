/*
** init.c for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/source/launch
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Tue Mar 22 14:41:29 2016 Flora Huot
** Last update Tue Mar 22 14:41:29 2016 Flora Huot
*/

#include "application.h"
#include "flag.h"
#include "my.h"

int	create_prog_info(t_info_list **new)
{
  *new = malloc(sizeof(t_info_list));
  if (*new == NULL)
    {
      my_putstr("Malloc returned null!\n", 2);
      return (1);
    }
  (*new)->file_name = NULL;
  (*new)->live_code = -1;
  (*new)->address = -1;
  (*new)->next = NULL;
  return (0);
}

int		handle_option_flag(t_application *app, char **flags)
{
  int		*target;

  if (!my_strcmp(*flags, "-a"))
    target = &app->program_list->address;
  else if (!my_strcmp(*flags, "-n"))
    target = &app->program_list->live_code;
  else if (!my_strcmp(*flags, "-dump"))
    target = &app->dump_cycle;
  else
    {
      my_putstr("Error: Unknow option ", 2);
      my_putstr(*flags, 2);
      my_putstr("\n", 2);
      return (1);
    }
  if (!flags[1])
    {
      my_putstr("Error: Missing number after ", 2);
      my_putstr(*flags, 2);
      my_putstr(" argument\n", 2);
      return (1);
    }
  return (set_option_flag(app, flags, target));
}
