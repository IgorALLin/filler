/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alarm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 21:57:40 by ichebota          #+#    #+#             */
/*   Updated: 2017/04/17 21:57:42 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_simple_try_rev(t_st *st)
{
	int		i;

	i = st->bx * st->py - 1;
	while(i >= 0)
	{
        if (ft_try(st, i) == 1)
        {
			st->resy = i / st->bx;
			st->resx = i % st->bx;
            return ;
        }
        i--;
	}
}

void	ft_simple_try(t_st *st)
{
	int		i;
	
	i = 0;
	if (st->pos == 2)
	{
		ft_simple_try_rev(st);
		return ;
	}
    while(st->board[i])
    {
        if (ft_try(st, i) == 1)
        {
            st->resy = i / st->bx;
			st->resx = i % st->bx;
            return ;
        }
        i++;
    }
}

int		ft_alarm_rev(t_st *st)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while(st->board[i])
	{
		if (ft_check_enemy(st->player, st->board[i]) == 1)
    		ret = 1;
    	else if (ft_check_enemy(st->player, st->board[i]) == 2)
			ret = 2;
		i++;
	}
	if (ret == 1)
	{	
		ft_simple_try(st);
		return (1);
	}
	return (0);
}

int		ft_alarm(t_st *st)
{
	int		i;

	i = 0;
	if (st->pos == 2)
		return (ft_alarm_rev(st));
	while (st->board[i])
    {
    	if (ft_check_enemy(st->player, st->board[i]) == 1)
    	{
    		ft_simple_try(st);
			return (1);
    	}
    	else if (ft_check_enemy(st->player, st->board[i]) == 2)
			return (0);
        i++;
    }
	return (0);
}