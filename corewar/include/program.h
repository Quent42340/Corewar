/*
** program.h for  in /home/bazin_q/rendu/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 23 12:16:14 2016 Quentin Bazin
** Last update Sun Mar 27 21:44:45 2016 Jakob Kellendonk
*/

#ifndef PROGRAM_H_
# define PROGRAM_H_

# include "args.h"
# include "error.h"
# include "op.h"

struct s_application;

# define CMD_MAX_SIZE (1 + 1 + MAX_ARGS_NUMBER * DIR_SIZE)

struct		s_program;

typedef struct		s_process
{
  unsigned char		cmd[CMD_MAX_SIZE];
  int			cycles_left;
  int			carry;
  int			pc;
  struct s_program	*parent;
  unsigned char		registre[REG_NUMBER][REG_SIZE];
}			t_process;

typedef struct		s_program
{
  struct s_header	info;
  int			live;
  t_process		*processes;
  int			process_amount;
  int			did_live;
  int			index;
  int			last_live_cycle;
  int			is_alive;
}			t_program;

t_err	add_process(t_program *program, t_info_list *list);
t_err	program_init(t_program *program, struct s_application *app,
		     t_info_list *list, int index);
t_err	set_address(struct s_application *app, t_program *program,
		    t_info_list *list);

void	message_alive(t_program *program, int player);
void	message_win(t_program *program, int player);

#endif /* !PROGRAM_H_ */
