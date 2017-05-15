/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:05:06 by ichebota          #+#    #+#             */
/*   Updated: 2017/05/09 19:05:07 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_pos(t_st *st)
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
	st->pos = 0;
	while (ft_reader(st) != 0)
	{
		if (st->pos == 0)
			ft_pos(st);
		ft_game(st);
		ft_print_res(st);
	}
	return (0);
}
