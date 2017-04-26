/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 20:23:22 by ichebota          #+#    #+#             */
/*   Updated: 2017/04/26 20:23:24 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_diagonal(t_st *st, int i, int sum)
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
			res = res + ft_modul(st, i1, 16);
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

int		ft_check_min(t_st *st)
{
	int		i;

	i = 0;
	while (st->board[i])
	{
		if (i % st->bx == 0 && ft_check_enemy(st->player, st->board[i]) == 2)
			return (1);
		i++;
	}
	return (0);
}

int		ft_kill_him(t_st *st, int i, int sum)
{
	int		res;
	int		in;
	int		i1;

	in = 0;
	i1 = i;
	res = -1;
	while (st->piece[in])
	{
		if (in != 0 && in % st->px == 0)
			i1 = i1 + st->bx - st->px;
		if ((st->piece[in] == '*' && st->board[i1] == '.') &&
			(res == -1 || i1 % st->bx < res))
			res = i1 % st->bx;
		i1++;
		in++;
	}
	if (st->resy == 0 || res < sum)
	{
		sum = res;
		st->resy = i / st->bx;
		st->resx = i % st->bx;
	}	
	return (sum);
}

void	ft_map00(t_st *st)
{
	int		i;
	int		sum;
	int		minx;

	i = 0;
	sum = 0;
	minx = ft_check_min(st);
	while(st->by - i / st->bx >= st->py)
	{
		if (ft_try(st, i) == 1)
		{
			if (minx == 0)
				sum = ft_kill_him(st, i, sum);
			else
				sum = ft_diagonal(st, i, sum);
		}
		i++;	
	}
	ft_print_res(st);
}