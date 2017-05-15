/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:15:03 by ichebota          #+#    #+#             */
/*   Updated: 2017/05/09 18:15:05 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_put_res(t_st *st, t_cors *cors, int res)
{
	if (st->sum == 0 || res < st->sum)
	{
		st->sum = res;
		st->resx = cors->x;
		st->resy = cors->y;
	}
}

void	ft_print_res(t_st *st)
{
	ft_putnbr(st->resy);
	ft_putchar(' ');
	ft_putnbr(st->resx);
	ft_putchar('\n');
}

int		ft_check_enemy(int player, char ch)
{
	if (player == 1 && (ch == 'x' || ch == 'X'))
		return (1);
	else if (player == 2 && (ch == 'o' || ch == 'O'))
		return (1);
	else if (player == 2 && (ch == 'x' || ch == 'X'))
		return (2);
	else if (player == 1 && (ch == 'o' || ch == 'O'))
		return (2);
	return (0);
}
