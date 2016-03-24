/*
** run.h for corewar in /home/kellen_j/rendu/CPE_2015_corewar/corewar
** 
** Made by Jakob Kellendonk
** Login   <kellen_j@epitech.net>
** 
** Started on  Thu Mar 24 13:22:51 2016 Jakob Kellendonk
** Last update Thu Mar 24 17:57:21 2016 Jakob Kellendonk
*/

#ifndef RUN_H_
# define RUN_H_

# include "application.h"

# define GET_CYCLE_AMOUNT(i) (i > 0 && i <= 16 && op_tab[i - 1].nbr_cycles)

t_err	tick(t_application *application);

#endif /* !RUN_H_ */
