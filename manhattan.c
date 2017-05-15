/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manhattan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:03:25 by ichebota          #+#    #+#             */
/*   Updated: 2017/05/09 19:03:27 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

int		ft_next_point(t_st *st, int i)
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

void	ft_manhattan(t_st *st, t_cors *cors)
{
	int		res;
	int		i1;
	int		i;

	while (cors)
	{
		res = 0;
		i1 = cors->i;
		i = 0;
		while (st->piece[i])
		{
			if (i != 0 && i % st->px == 0)
				i1 = i1 + st->bx - st->px;
			if (st->piece[i] == '*' && st->board[i1] == '.')
				res = res + ft_next_point(st, i1);
			i1++;
			i++;
		}
		ft_put_res(st, cors, res);
		cors = cors->next;
	}
}
