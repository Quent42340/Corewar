/*
** file_reader.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 19:45:48 2016 Benjamin Grange
** Last update Tue Feb 23 23:34:30 2016 Benjamin Grange
*/

#ifndef FILE_READER_H_
# define FILE_READER_H_

# include "position.h"

typedef struct			s_asm_file_reader
{
  t_asm_position		cursor;
  t_asm_program_file		*file;
}				t_asm_file_reader;

#endif /* !FILE_READER_H_ */
