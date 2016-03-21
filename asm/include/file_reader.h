/*
** file_reader.h for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Tue Feb 23 19:45:48 2016 Benjamin Grange
** Last update Mon Mar 21 14:44:31 2016 Benjamin Grange
*/

#ifndef FILE_READER_H_
# define FILE_READER_H_

# include "position.h"
# include "basic.h"

typedef struct			s_file_reader
{
  t_position			cursor;
  t_program_file		*file;
}				t_file_reader;

t_file_reader		generate_file_reader(t_program_file *);
int			string_reader_skip(t_file_reader *, char *);
int			string_reader_skip_whitespace(t_file_reader *);
char			string_reader_next(t_file_reader *);
t_bool			string_reader_has_more(t_file_reader *);
t_file_reader		string_reader_create(t_program_file *, const char *);
t_bool			file_reader_read_string(t_file_reader *file_reader,
						char *string);

#endif /* !FILE_READER_H_ */
