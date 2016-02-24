/*
** token.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Feb 24 13:33:25 2016 Benjamin Grange
** Last update Wed Feb 24 14:41:41 2016 Benjamin Grange
*/

#include "asm.h"

t_token		create_token(t_file_reader *reader,
			     t_position begin,
			     t_token_type type)
{
  t_token	token;
  unsigned int	length;

  length = reader->cursor.index - begin.index;
  token.begin = begin;
  token.end = reader->cursor;
  token.type = type;
  token.content_string = my_strndup(reader->file->content + begin.index,
				    length);
  my_memset(&token.content, 0, sizeof(t_token_content));
  return (token);
}

void		delete_token(t_token *token)
{
  xfree(token->content_string);
}
