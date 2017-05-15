/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:06:47 by ichebota          #+#    #+#             */
/*   Updated: 2017/05/09 19:10:52 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/stat.h>

# define BUFF_SIZE 1

typedef struct				s_filler
{
	char					*board;
	char					*piece;
	int						player;
	int						bx;
	int						by;
	int						px;
	int						py;
	int						resx;
	int						resy;
	int						pos;
	int						alarm;
	int						sum;
}							t_st;

typedef struct				s_clist
{
	int						i;
	int						x;
	int						y;
	struct s_clist			*next;
}							t_cors;

void						ft_game(t_st *st);
int							ft_reader(t_st *st);
int							ft_check_enemy(int player, char ch);
void						ft_manhattan(t_st *st, t_cors *cors);
int							ft_try(t_st *st, int i);
void						ft_print_res(t_st *st);
int							ft_modul(t_st *st, int i, int in);
void						ft_map00(t_st *st, t_cors *cors);
void						ft_print_res(t_st *st);
void						ft_put_res(t_st *st, t_cors *cors, int res);
int							get_next_line(const int fd, char **line);
void						ft_print_res(t_st *st);

#endif
