/*
** args.h for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 23 12:12:05 2016 Quentin Bazin
** Last update Wed Mar 23 12:12:05 2016 Quentin Bazin
*/
#ifndef ARGS_H_
# define ARGS_H_

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
  int			program_amount;
}			t_args;

int	args_init(t_args *args, int argc, char **argv);
void	args_free(t_args *args);

#endif /* !ARGS_H_ */
