/*
** token.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Feb 24 13:33:25 2016 Benjamin Grange
** Last update Mon Mar 21 16:30:02 2016 Benjamin Grange
*/

#include "asm.h"

void		print_token(t_token t)
{
  char		*message[TOKEN_TYPE_COUNT];

  message[0] = "INSTRUCTION";
  message[1] = "REGISTER";
  message[2] = "INTEGER";
  message[3] = "LABEL_VALUE";
  message[4] = "OPERATOR";
  message[5] = "STRING";
  message[6] = "CONFIG";
  message[7] = "COMMENT";
  message[8] = "LABEL";
  message[9] = "WHITESPACE";
  message[10] = "EOL";
  my_putstr(DARKGREY);
  my_putstr("{");
  my_putstr(message[t.type]);
  if (t.type != TOKEN_TYPE_EOL)
    {
      my_putstr(" : [");
      my_putstr(t.content_string);
      my_putstr("]");
    }
  my_putstr("}" WHITE);
  my_putchar('\n');
}

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
  if (DEBUG)
    print_token(token);
  return (token);
}
