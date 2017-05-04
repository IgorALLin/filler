#include "filler.h"

int		ft_check_enemy(int player, char ch)
{
	if (player == 1 && (ch == 'x' || ch == 'X'))
		return(1);
	else if(player == 2 && (ch == 'o' || ch == 'O'))
		return (1);
	else if (player == 2 && (ch == 'x' || ch == 'X'))
		return(2);
	else if(player == 1 && (ch == 'o' || ch == 'O'))
		return (2);
	return (0);
}

void		ft_pos(t_st *st)
{
	int		i;

	i = 0;
	while (st->board[i])
	{
		if (ft_check_enemy(st->player, st->board[i]) == 1)
		{
			st->pos = 2;
			return ;
		}
		else if (ft_check_enemy(st->player, st->board[i]) == 2)
		{
			st->pos = 1;
			return ;
		}
		i++;
	}
}

int		main(void)
{
	t_st	*st;

	st = (t_st *)malloc(sizeof(*st));
	while (ft_reader(st) != 0)
		ft_game(st);
	return(0);
}