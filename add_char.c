/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:11:28 by ichebota          #+#    #+#             */
/*   Updated: 2017/03/07 17:23:33 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_add_char_hex(char *str, char ch)
{
	char	*ret;
	int		i;
	int		i1;

	i = 0;
	i1 = 2;
	ret = ft_strnew(ft_strlen(str) + 2);
	while (i < 2)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = ch;
	i++;
	while (str[i1])
	{
		ret[i] = str[i1];
		i++;
		i1++;
	}
	return (ret);
}

char	*ft_add_char_first(char *str, char ch)
{
	char	*res;
	int		i;
	int		i1;

	i = 1;
	i1 = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	res[0] = ch;
	while (str[i1])
	{
		res[i] = str[i1];
		i++;
		i1++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_add_char(char *str, char ch)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_strnew(ft_strlen(str) + 2);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
    free(str);
	ret[i] = ch;
	return (ret);
}
