/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:25:33 by ichebota          #+#    #+#             */
/*   Updated: 2017/01/31 15:27:26 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_newfile(int fd)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	list->content = ft_strnew(0);
	list->content_size = fd;
	list->next = NULL;
	return (list);
}

t_list	*ft_read_fd(t_list **files, int fd)
{
	t_list *ret;

	ret = *files;
	while (ret)
	{
		if (ret->content_size == (unsigned long)fd)
			return (ret);
		ret = ret->next;
	}
	ret = ft_newfile(fd);
	ft_lstadd(files, ret);
	return (ret);
}

int		ft_joincontent(int fd, void **content)
{
	char	buf[BUFF_SIZE + 1];
	int		rd;
	char	*tmp;
	char	*ptr;

	while ((rd = read(fd, buf, BUFF_SIZE)))
	{
		if (rd < 0)
			return (-1);
		buf[rd] = '\0';
		tmp = ft_strjoin(*content, buf);
		ft_memdel(content);
		*content = tmp;
		ft_bzero(buf, ft_strlen(buf));
		if ((ptr = ft_strchr(*content, '\n')))
			break ;
	}
	return (rd);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*h;
	int				rd;
	char			*ptr;

	h = ft_read_fd(&files, fd);
	if (fd < 0 || BUFF_SIZE < 0 || line == NULL ||
			(rd = ft_joincontent(fd, &h->content)) < 0)
		return (-1);
	if (rd == 0 && !ft_strlen(h->content))
		return (0);
	if ((ptr = ft_strchr(h->content, '\n')))
	{
		*ptr = '\0';
		*line = ft_strdup(h->content);
		ft_memmove(h->content, ptr + 1, ft_strlen(ptr + 1) + 1);
		return (1);
	}
	if (!(ptr = ft_strchr(h->content, '\n')) && ft_strlen(h->content) != 0)
	{
		*line = ft_strdup(h->content);
		ft_bzero(h->content, ft_strlen(h->content));
		return (1);
	}
	return (0);
}
