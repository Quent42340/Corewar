/*
** basic.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 22:35:39 2016 Benjamin Grange
** Last update Tue Feb 23 22:59:49 2016 Benjamin Grange
*/

#ifndef BASIC_H_
# define BASIC_H_

# include "asm.h"

# define TRUE 1
# define FALSE 0

typedef unsigned char		t_byte;
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;
typedef unsigned char		t_bool;

ssize_t		my_putchar(char);
ssize_t		my_putstr(char *);
ssize_t		my_strlen(char *);
char		*my_strdup(char *);
void		*xmalloc(size_t);
void		*xrealloc(void *, size_t);
void		xfree(void *);
void		*my_memset(void *, t_byte, size_t);
void		*my_memcpy(void *, void *, size_t);

#endif /* !BASIC_H_ */
