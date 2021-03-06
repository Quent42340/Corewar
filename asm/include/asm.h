/*
** asm.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 17:14:54 2016 Benjamin Grange
** Last update Sun Mar 27 16:50:33 2016 Benjamin Grange
*/

#ifndef ASM_H_
# define ASM_H_

# ifndef LEXER_DEBUG
#  define LEXER_DEBUG 0
# endif /* !LEXER_DEBUG */

# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "basic.h"
# include "file_reader.h"
# include "file.h"
# include "position.h"
# include "token.h"
# include "op.h"

void		compile_file(char *);

#endif /* !ASM_H_ */
