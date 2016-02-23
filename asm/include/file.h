/*
** file.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 19:31:17 2016 Benjamin Grange
** Last update Tue Feb 23 23:34:46 2016 Benjamin Grange
*/

#ifndef FILE_H_
# define FILE_H_

typedef struct		s_asm_program_file
{
  char			*name;
  char			*path;
  char			*content;
}			t_asm_program_file;

t_asm_program_file	program_file_create(char *);

#endif /* !FILE_H_ */
