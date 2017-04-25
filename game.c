#include "filler.h"

void	ft_print_res(t_st *st)
{
	ft_putnbr(st->resy);
	ft_putchar(' ');
	ft_putnbr(st->resx);
	ft_putchar('\n');
}

int		ft_try(t_st *st, int x, int i)
{
	int		over;
	int		in;

	in = 0;
	over = 0;
	if (st->bx - x < st->px)
		return (0);
	while(st->piece[in])
	{
		if (st->piece[in] == '\n')
			i = i + st->bx - st->px;
		else if(over > 1 || (st->piece[in] == '*' &&
			ft_check_enemy(st->player, st->board[i]) == 1))
			return (0);
		else if (st->piece[in] == '*' &&
			ft_check_enemy(st->player, st->board[i]) == 2)
			over++;
		i++;
		in++;
	}
	if (over == 1)
		return (1);
	return (0);
}

void	ft_game(t_st *st)
{
	int		i;
	int		x;
	int		y;
	int		sum;

	i = 0;
	x = 0;
	y = 0;
	sum = 0;
	st->resx = 0;
	st->resy = 0;
	if (st->by == 15)
	{
		ft_map00(st);
		ft_print_res(st);
		return ;
	}
	if (ft_alarm(st) == 1)
	{
		ft_print_res(st);
		return ;	
	}
	while(st->board[i])
	{
		if (st->by - y < st->py)
			break ;
		if (st->board[i] == '\n')
		{
			y++;
			x = -1;
		}
		else if (ft_try(st, x, i) == 1)
			sum = ft_manhattan(st, y, x, i, sum);
		i++;
		x++;	
	}
	ft_print_res(st);
}