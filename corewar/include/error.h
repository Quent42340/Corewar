/*
** error.h for  in /blinux_home/huot_b/rendus/CPE/CPE_2015_corewar/corewar/include
** 
** Made by Flora Huot
** Login   <huot_b@epitech.net>
** 
** Started on  Wed Mar 23 11:17:26 2016 Flora Huot
** Last update Sat Mar 26 13:46:38 2016 Jakob Kellendonk
*/

#ifndef ERROR_H_
# define ERROR_H_

/* Ne pas oublier d'augmenter le compteur à chaque ajout */
# define ERROR_COUNT 10

typedef enum				e_err
{
  ERROR_UNKNOWN				= -1,
  ERROR_MALLOC_FAILED			= 1,
  ERROR_OPEN_FAILED			= 2,
  ERROR_UNKNOWN_OPTION			= 3,
  ERROR_MISSING_NUMBER			= 4,
  ERROR_POSITIVE_NUMBER_EXPECTED	= 5,
  ERROR_INTEGER_EXPECTED		= 6,
  ERROR_NOT_EXECUTABLE			= 7,
  ERROR_FILE_NOT_ACCESSIBLE		= 8,
  ERROR_WRONG_PROGRAM_AMOUNT		= 9,
  ERROR_OVERLAP				= 10
}					t_err;

void	fill_error_messages(char *messages[ERROR_COUNT]);

void	print_usage(char *program_name);
t_err	print_error(t_err error, ...);

#endif /* !ERROR_H_ */
