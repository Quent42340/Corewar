/*
** args.h for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 23 12:12:05 2016 Quentin Bazin
** Last update Sat Mar 26 16:49:32 2016 Jakob Kellendonk
*/
#ifndef ARGS_H_
# define ARGS_H_

# include "error.h"

struct s_application;
struct s_program;

typedef struct		s_constants
{
  int			cycle_delta;
  int			nbr_live;
  int			dump_cycle;
}			t_constants;

typedef struct		s_info_list
{
  int			live_code;
  int			address;
  char			*file_name;
  struct s_info_list	*next;
}			t_info_list;

typedef struct		s_args
{
  int			cycle_to_die;
  t_constants		*constants;
  t_info_list		*program_list;
  void			(*death_callback)(struct s_application *,
					  struct s_program *);
  void			(*st_callback)(struct s_application *,
				       struct s_program *,
				       int index, int size);
  int			program_amount;
}			t_args;

t_err	args_init(t_args *args, char **argv);
void	args_free(t_args *args);

#endif /* !ARGS_H_ */
