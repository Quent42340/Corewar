/*
** file.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 19:31:17 2016 Benjamin Grange
** Last update Wed Feb 24 13:09:18 2016 Benjamin Grange
*/

#ifndef FILE_H_
# define FILE_H_

typedef struct		s_program_file
{
  char			*name;
  char			*path;
  char			*content;
  unsigned int		file_size;
}			t_program_file;

t_program_file		program_file_create(char *);

#endif /* !FILE_H_ */
