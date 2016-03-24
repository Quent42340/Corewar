/*
** flag.h for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Tue Mar 22 14:42:17 2016 Flora Huot
** Last update Tue Mar 22 17:00:06 2016 Jakob Kellendonk
*/

#ifndef FLAG_H_
# define FLAG_H_

# include "application.h"

t_err	create_prog_info(t_info_list **new);
t_err	handle_option_flag(t_args *args, char **flags);

t_err	set_option_flag(t_args *args, char **falgs, int *target);
int	set_default_values(t_args *args);
int	validate_args_state(t_args *args);

#endif /* !FLAG_H_ */
