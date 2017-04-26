#include "filler.h"

void    ft_player(char *line, t_st *st)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		i++;
	if (line[i] == '1')
		st->player = 1;
	else	
		st->player = 2;
}

void		ft_size(t_st *st, char *line, int i)
{
	char	*num;
	int		in;

	in = i;
	num = ft_strnew(1);
	while(ft_isdigit(line[in]) == 1)
	{
		num = ft_add_char(num, line[in]);
		in++;
	}
	if (i == 8)
		st->by = ft_atoi(num);
	else
		st->py = ft_atoi(num);
	while(ft_isdigit(line[in]) != 1)
		in++;
	num = ft_strnew(1);
	while(ft_isdigit(line[in]) == 1)
	{
		num = ft_add_char(num, line[in]);
		in++;
	}
	if (i == 8)
		st->bx = ft_atoi(num);
	else
		st->px = ft_atoi(num);
}

void	ft_piece(t_st *st)
{
	char	*line;
	int		i;

	i = -1;
	st->piece = ft_strnew(st->px * st->py);
	while (++i < st->py)
	{
		get_next_line(0, &line);
		st->piece = ft_strjoin(st->piece, line);
		free(line);
	}
}

void	ft_board(t_st *st)
{
	int		i;
	char	*line;
	char 	*tmp;
	
	i = -1;
	get_next_line(0, &line);
	st->board = ft_strnew(st->bx * st->by);
	while (++i < st->by)
	{
		get_next_line(0, &line);
		tmp = line;
		tmp += 4;
		st->board = ft_strjoin(st->board, tmp);
		free(line);
	}
}

int		ft_reader(t_st *st)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) != 0)
	{
		if ((ft_strstr(line, "/filler]") != NULL))
		{
			ft_player(line, st);
			free(line);
		}
		else if (line[0] == 'P' && line[1] == 'l')
		{
			ft_size(st, line, 8);
			ft_board(st);
		}
		else if (line[0] == 'P' && line[1] == 'i')
		{
			ft_size(st, line, 6);
			ft_piece(st);
			return (1);
		}			
	}
	return (0);
}