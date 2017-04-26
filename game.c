#include "filler.h"

void	ft_print_res(t_st *st)
{
	ft_putnbr(st->resy);
	ft_putchar(' ');
	ft_putnbr(st->resx);
	ft_putchar('\n');
}

int		ft_try(t_st *st, int i)
{
	int		over;
	int		in;

	in = 0;
	over = 0;
	if (st->bx - i % st->bx < st->px)
		return (0);
	while(st->piece[in])
	{
		if (in != 0 && in % st->px == 0)
			i = i + st->bx - st->px;
		if(over > 1 || (st->piece[in] == '*' &&
			ft_check_enemy(st->player, st->board[i]) == 1))
			return (0);
		if (st->piece[in] == '*' &&
			ft_check_enemy(st->player, st->board[i]) == 2)
			over++;
		i++;
		in++;
	}
	if (over == 1)
		return (1);
	return (0);
}

int		ft_next_piece(t_st *st, int i, int sum)
{
	int		res;
	int		in;
	int		i1;

	in = 0;
	i1 = i;
	res = 0;
	while (st->piece[in])
	{
		if (in != 0 && in % st->px == 0)
			i1 = i1 + st->bx - st->px;
		if (st->piece[in] == '*' && st->board[i1] == '.')
			res = res + ft_manhattan(st, i1);
		i1++;
		in++;
	}
	if (sum == 0 || res < sum)
	{
		sum = res;
		st->resy = i / st->bx;
		st->resx = i % st->bx;
	}
	return (sum);
}

void	ft_game(t_st *st)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	st->resx = 0;
	st->resy = 0;
	if (st->by == 15)
	{
		ft_map00(st);
		return ;
	}
	if (ft_alarm(st) == 1)
	{
		ft_print_res(st);
		return ;	
	}
	while(st->by - i / st->bx >= st->py)
	{
		if (ft_try(st, i) == 1)
			sum = ft_next_piece(st, i, sum);
		i++;	
	}
	ft_print_res(st);
}