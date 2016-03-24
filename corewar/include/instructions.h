/*
** instructions.h for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Thu Mar 24 17:17:09 2016 Flora Huot
** Last update Thu Mar 24 17:17:09 2016 Flora Huot
*/

#ifndef INSTRUCTIONS_H_
# define INSTRUCTIONS_H_

# include "application.h"
# include "program.h"

t_err	instruction_live(t_application *app, t_process *proc);
t_err	instruction_zjmp(t_application *app, t_process *proc);
t_err	instruction_aff(t_application *app, t_process *proc);

t_err	instruction_ld(t_application *app, t_process *proc);
t_err	instruction_ldi(t_application *app, t_process *proc);
t_err	instruction_lld(t_application *app, t_process *proc);
t_err	instruction_lldi(t_application *app, t_process *proc);

t_err	instruction_st(t_application *app, t_process *proc);
t_err	instruction_sti(t_application *app, t_process *proc);

t_err	instruction_add(t_application *app, t_process *proc);
t_err	instruction_sub(t_application *app, t_process *proc);
t_err	instruction_and(t_application *app, t_process *proc);
t_err	instruction_or(t_application *app, t_process *proc);
t_err	instruction_xor(t_application *app, t_process *proc);

t_err	instruction_fork(t_application *app, t_process *proc);
t_err	instruction_lfork(t_application *app, t_process *proc);

#endif /* !INSTRUCTIONS_H_ */
