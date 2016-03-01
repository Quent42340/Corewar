/*
** basic.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 22:35:39 2016 Benjamin Grange
** Last update Tue Mar  1 02:52:40 2016 Benjamin Grange
*/

#ifndef BASIC_H_
# define BASIC_H_

# include <unistd.h>

# define TRUE 1
# define FALSE 0

/*
** Colors
*/
# define WHITE	"\033[00;0m"
# define DARKGREY "\033[0;90;1m"
# define GREEN	"\033[0;32;1m"
# define RED "\033[0;31;1m"
# define CYAN "\033[0;36;1m"
# define YELLOW "\033[0;33;1m"

typedef unsigned char		t_byte;
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;
typedef unsigned char		t_bool;

ssize_t		my_putchar(char);
ssize_t		my_putstr(char *);
ssize_t		my_putnbr_error(int);
ssize_t		my_putchar_error(char);
ssize_t		my_puterror(char *);
int		my_strcmp(char *, char *);
void		my_cpystr(char *, char *);
void		*print_error_n(char *);
int		print_error_i(char *, int);
ssize_t		my_strlen(char *);
t_bool		is_char_printable(char);
char		*my_strchr(char *, char);
char		*my_strdup(char *);
char		*my_strndup(char *, size_t);
void		*xmalloc(size_t);
void		*xrealloc(void *, size_t);
void		xfree(void *);
void		*my_memset(void *, t_byte, size_t);
void		*my_memcpy(void *, void *, size_t);

#endif /* !BASIC_H_ */
