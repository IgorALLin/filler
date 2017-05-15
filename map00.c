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

int		ft_checkmax(t_st *st)
{
	int		i;

	i = 0;
	while (st->board[i])
	{
		if ((i + 1) % st->bx == 0 &&
			ft_check_enemy(st->player, st->board[i]) == 2)
			return (1);
		else if (i < st->bx && ft_check_enemy(st->player, st->board[i]) == 2)
			return (1);
		i++;
	}
	return (0);
}

int		ft_map00_piece(t_st *st, t_cors *cors)
{
	int		i;
	int		i1;
	int		res;

	i = 0;
	res = 0;
	i1 = cors->i;
	while (st->piece[i])
	{
		if (i != 0 && i % st->px == 0)
			i1 = i1 + st->bx - st->px;
		if (i1 == 136 && st->board[i1] == '.' && st->piece[i] == '*')
		{
			st->resx = cors->x;
			st->resy = cors->y;
			return (1);
		}
		if (st->piece[i] == '*' && st->board[i1] == '.')
			res = res + ft_modul(st, i1, 63);
		i1++;
		i++;
	}
	ft_put_res(st, cors, res);
	return (0);
}

int		ft_up(t_st *st)
{
	int		i;

	i = 0;
	while (st->board[i])
	{
		if (ft_check_enemy(st->player, st->board[i]) == 1)
			return (0);
		if (ft_check_enemy(st->player, st->board[i]) == 2)
			return (1);
		i++;
	}
	return (0);
}

void	ft_map002(t_st *st, t_cors *cors)
{
	if (ft_up(st) == 1)
	{
		ft_manhattan(st, cors);
		return ;
	}
	if (cors)
	{
		st->resx = cors->x;
		st->resy = cors->y;
	}
	while (cors)
	{
		if (cors->y <= st->resy)
		{
			st->resy = cors->y;
			st->resx = cors->x;
		}
		cors = cors->next;
	}
}

void	ft_map00(t_st *st, t_cors *cors)
{
	if (st->player == 2)
		ft_map002(st, cors);
	if (ft_checkmax(st) == 1)
		ft_manhattan(st, cors);
	while (cors)
	{
		if (ft_map00_piece(st, cors) == 1)
			return ;
		cors = cors->next;
	}
}
