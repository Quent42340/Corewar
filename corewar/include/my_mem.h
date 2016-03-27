/*
** my_mem.h for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Wed Mar 23 11:09:07 2016 Flora Huot
** Last update Fri Mar 25 18:04:54 2016 Jakob Kellendonk
*/

#ifndef MY_MEM_H_
# define MY_MEM_H_

#include <my.h>
# include <unistd.h>

# define WSIZE sizeof(unsigned int)
# define WMASK (WSIZE - 1)

int	my_getnbr_error(char *str, int *error);
int	char_to_int(unsigned char *src);
int	char_to_short(unsigned char *src);
int	int_to_char(int nb, unsigned char *str);
void	*my_memcpy(void *dest, void *src, size_t n);
void	*my_memset(void *src, register char c, register size_t n);
void	my_putstr_out(char *str, int out);

#endif /* !MY_MEM_H_ */
