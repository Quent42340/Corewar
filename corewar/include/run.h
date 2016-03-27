/*
** run.h for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Thu Mar 24 13:22:51 2016 Jakob Kellendonk
** Last update Tue Mar 29 19:42:04 2016 Jakob Kellendonk
*/

#ifndef RUN_H_
# define RUN_H_

# include "application.h"

# define GET_CYCLE_AMOUNT(i) (i > 0 && i <= 16 && op_tab[i - 1].nbr_cycles)

t_err	tick(t_application *application);

typedef t_err	(*t_func)(t_application *, t_process **);

t_err	instruction_live(t_application *app, t_process **proc);
t_err	instruction_zjmp(t_application *app, t_process **proc);
t_err	instruction_aff(t_application *app, t_process **proc);
t_err	instruction_add(t_application *app, t_process **proc);
t_err	instruction_sub(t_application *app, t_process **proc);
t_err	instruction_and(t_application *app, t_process **proc);
t_err	instruction_or(t_application *app, t_process **proc);
t_err	instruction_xor(t_application *app, t_process **proc);
t_err	instruction_fork(t_application *app, t_process **proc);
t_err	instruction_lfork(t_application *app, t_process **proc);
t_err	instruction_ld(t_application *app, t_process **proc);
t_err	instruction_ldi(t_application *app, t_process **proc);
t_err	instruction_lld(t_application *app, t_process **proc);
t_err	instruction_lldi(t_application *app, t_process **proc);
t_err	instruction_st(t_application *app, t_process **proc);
t_err	instruction_sti(t_application *app, t_process **proc);

t_err	dump_vm(t_application *app);
t_err	end_game(t_application *app);

#endif /* !RUN_H_ */
