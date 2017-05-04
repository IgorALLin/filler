#ifndef INCLUDES_H
# define INCLUDES_H

# include <stdio.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"

typedef struct s_filler
{
	char 		*board;
	char 		*piece;
	int			player;
	int			bx;
	int			by;
	int			px;
	int			py;
	int			resx;
	int			resy;
	int			pos;
	int			alarm;
}				t_st;

char	*ft_add_char(char *str, char ch);
void	ft_game(t_st *st);
int		ft_reader(t_st *st);
int		ft_check_enemy(int player, char ch);
int		ft_manhattan(t_st *st, int i);
int		ft_try(t_st *st, int i);
void	ft_print_res(t_st *st);
int		ft_modul(t_st *st, int i, int in);

#endif