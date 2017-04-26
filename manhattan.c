#include "filler.h"

int		ft_modul(t_st *st, int i, int in)
{
	int		num1;
	int		num2;

	num1 = i / st->bx - in / st->bx;
	num2 = i % st->bx - in % st->bx;
	if (num1 < 0)
		num1 = -num1;
	if (num2 < 0)
		num2 = -num2;
	return (num1 + num2);
}

int		ft_sum2(t_st *st, int i)
{
	int		in;

	in = i;
	while (in >= 0)
	{
		if (ft_check_enemy(st->player, st->board[in]) == 1)
			return (ft_modul(st, i, in));
		in--;
	}
	return (0);
}

int		ft_sum1(t_st *st, int i)
{
	int		in;

	in = i;
	while (st->board[in])
	{
		if (ft_check_enemy(st->player, st->board[in]) == 1)
			return (ft_modul(st, i, in));
		in++;
	}
	return (0);
}

int		ft_manhattan(t_st *st, int i)
{
	int		res1;
	int		res2;
	
	res1 = ft_sum1(st, i);
	res2 = ft_sum2(st, i);
	if (res1 == 0)
		return (res2);
	else if (res2 == 0)
		return (res1);
	else if (res1 < res2)
		return (res1);
	return (res2);
}
