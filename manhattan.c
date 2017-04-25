#include "filler.h"

int		ft_modul(int y, int x, int j, int i)
{
	int		num1;
	int		num2;

	num1 = y - j;
	num2 = x - i;
	if (num1 < 0)
		num1 = -num1;
	if (num2 < 0)
		num2 = -num2;
	return (num1 + num2);
}

int		ft_sum2(t_st *st, int y, int x, int i)
{
	int		res;
	int		j;
	int		in;

	j = y;
	in = x;
	res = 0;
	while (i >= 0)
	{
		if (st->board[i] == '\n')
		{
			j--;
			in = st->bx;
		}
		else if (ft_check_enemy(st->player, st->board[i]) == 1)
		{	
			res = ft_modul(y, x, j, in);
			return (res);
		}
		i--;
		in--;
	}
	return (res);
}

int		ft_sum1(t_st *st, int y, int x, int i)
{
	int		res;
	int		j;
	int		in;

	j = y;
	in = x;
	res = 0;
	while (st->board[i])
	{
		if (st->board[i] == '\n')
		{
			j++;
			in = x - 1;
		}
		else if (ft_check_enemy(st->player, st->board[i]) == 1)
		{	
			res = ft_modul(y, x, j, in);
			return (res);
		}	
		i++;
		in++;
	}
	return (res);
}

int		ft_count_sum(t_st *st, int y, int x, int i)
{
	int		res1;
	int		res2;
	
	res1 = ft_sum1(st, y, x, i);
	res2 = ft_sum2(st, y, x, i);
	if (res1 == 0)
		return (res2);
	else if (res2 == 0)
		return (res1);
	else if (res1 < res2)
		return (res1);
	return (res2);
}

int		ft_manhattan(t_st *st, int y, int x, int i, int sum)
{
	int		res;
	int		in;
	int		i1;
	int		j;

	in = 0;
	j = y;
	i1 = x;
	res = 0;
	while (st->piece[in])
	{
		if (st->piece[in] == '\n')
		{
			i = i + st->bx - st->px;
			j++;
			i1 = x - 1;
		}
		else if (st->piece[in] == '*' && st->board[i] == '.')
			res = res + ft_count_sum(st, j, i1, i);
		i++;
		in++;
		i1++;
	}
	if (sum == 0 || res < sum)
	{
		sum = res;
		st->resy = y;
		st->resx = x;
	}
	return (sum);
}