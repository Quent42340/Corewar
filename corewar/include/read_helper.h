/*
** read_helper.h for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Thu Mar 24 14:51:38 2016 Flora Huot
** Last update Thu Mar 24 14:51:38 2016 Flora Huot
*/

#ifndef READ_HELPER_H_
# define READ_HELPER_H_

# include "error.h"

t_err	read_int(int fd, int *target, char *file_name);
t_err	read_char(int fd, char *target, int nb, char *file_name);

#endif /* !READ_HELPER_H_ */
