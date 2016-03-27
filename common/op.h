/*
** op.h for corewar in /home/grange_c/rendu/cpe/CPE_2015_corewar/common/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Mon Feb 29 23:37:53 2016 Benjamin Grange
** Last update Sun Mar 27 16:48:43 2016 Benjamin Grange
*/

#ifndef OP_H_
# define OP_H_

# define MEM_SIZE		(6 * 1024)
# define IDX_MOD		512
# define MAX_ARGS_NUMBER	4

# define COMMENT_CHAR		'#'
# define LABEL_CHAR		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

# define REG_NUMBER		16
# define REG_SIZE		4

typedef char			t_args_type;

# define T_REG			1
# define T_DIR			2
# define T_IND			4
# define T_LAB			8

typedef struct			s_op
{
   char				*mnemonique;
   char				nbr_args;
   t_args_type			type[MAX_ARGS_NUMBER];
   char				code;
   int				nbr_cycles;
   char				*comment;
}				t_op;

extern t_op			op_tab[];

# define IND_SIZE		2
# define DIR_SIZE		REG_SIZE

# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048

# define COREWAR_EXEC_MAGIC	0xea83f3

typedef struct			s_header
{
   int				magic;
   char				prog_name[PROG_NAME_LENGTH + 1];
   int				prog_size;
   char				comment[COMMENT_LENGTH + 1];
}				t_header;

# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		5
# define NBR_LIVE		40

#endif
