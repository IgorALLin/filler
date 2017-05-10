/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:57:02 by ichebota          #+#    #+#             */
/*   Updated: 2017/05/09 18:57:04 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		ft_try(t_st *st, int i)
{
	int		over;
	int		in;

	in = 0;
	over = 0;
	if (st->bx - i % st->bx < st->px)
		return (0);
	while (st->piece[in])
	{
		if (in != 0 && in % st->px == 0)
			i = i + st->bx - st->px;
		if (over > 1 || (st->piece[in] == '*' &&
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

void	ft_next_piece(t_st *st, t_cors *cors)
{
	if (st->by == 15)
		ft_map00(st, cors);
	else
		ft_manhattan(st, cors);
}

void	ft_add_cors(t_cors **head, int data, t_st *st)
{
	t_cors	*tmp;

	tmp = (t_cors *)malloc(sizeof(t_cors));
	tmp->i = data;
	tmp->x = data % st->bx;
	tmp->y = data / st->bx;
	tmp->next = (*head);
	(*head) = tmp;
}

void	ft_game(t_st *st)
{
	int		i;
	t_cors	*cors;

	cors = NULL;
	i = 0;
	st->sum = 0;
	st->resx = 0;
	st->resy = 0;
	while (st->by - i / st->bx >= st->py)
	{
		if (ft_try(st, i) == 1)
			ft_add_cors(&cors, i, st);
		i++;
	}
	ft_next_piece(st, cors);
}
