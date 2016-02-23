/*
** position.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 19:27:55 2016 Benjamin Grange
** Last update Tue Feb 23 19:33:40 2016 Benjamin Grange
*/

#ifndef POSITION_H_
# define POSITION_H_

# include "file.h"

typedef struct		s_asm_position
{
  t_asm_program_file	*file;
  unsigned int		index;
  int			line;
  int			column;
}			t_asm_position;

#endif /* !POSITION_H_ */
