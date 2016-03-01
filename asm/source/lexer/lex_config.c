/*
** lex_config.c for asm in /home/grange_c/rendu/cpe/CPE_2015_corewar/asm/source/lexer/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Thu Feb 25 17:10:04 2016 Benjamin Grange
** Last update Tue Mar  1 02:45:03 2016 Benjamin Grange
*/

#include "lexer.h"

t_result		lex_config(t_file_reader *reader,
				   t_position begin,
				   char *string)
{
  if (my_strcmp(string, NAME_CMD_STRING))
    return (create_result_from_config_token(reader, begin, CONFIG_NAME));
  if (my_strcmp(string, COMMENT_CMD_STRING))
    return (create_result_from_config_token(reader, begin, CONFIG_COMMENT));
  return (get_null_result());
}
