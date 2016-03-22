/*
** my.h for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Tue Mar 22 14:34:23 2016 Flora Huot
** Last update Tue Mar 22 18:25:42 2016 Jakob Kellendonk
*/

#ifndef MY_H_
# define MY_H_

# include <unistd.h>

# define WSIZE sizeof(unsigned int)
# define WMASK ((1 << WSIZE) - 1)

int	my_getnbr(char *str, int *error);
int	my_strcmp(char *str_a, char *str_b);
int	my_strlen(char *str);
int	char_to_int(unsigned char *src);
int	char_to_short(unsigned char *src);
void	*my_memcpy(void *src, void *dest, register size_t n);
void	*my_memset(void *src, register char c, register size_t n);
void	my_putstr(char *str, int out);

#endif /* !MY_H_ */
