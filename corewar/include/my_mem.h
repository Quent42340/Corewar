/*
** my_mem.h for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Wed Mar 23 11:09:07 2016 Flora Huot
** Last update Wed Mar 23 11:09:07 2016 Flora Huot
*/

#ifndef MY_MEM_H_
# define MY_MEM_H_

#include <my.h>
# include <unistd.h>

# define WSIZE sizeof(unsigned int)
# define WMASK ((1 << WSIZE) - 1)

int	my_getnbr_error(char *str, int *error);
int	char_to_int(unsigned char *src);
int	char_to_short(unsigned char *src);
void	*my_memcpy(void *src, void *dest, register size_t n);
void	*my_memset(void *src, register char c, register size_t n);
void	my_putstr_out(char *str, int out);

#endif /* !MY_MEM_H_ */
