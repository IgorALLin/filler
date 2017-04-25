/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:21:25 by ichebota          #+#    #+#             */
/*   Updated: 2016/12/14 18:08:20 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_wrd(char const *s, int n)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char) * n + 1);
	while (--n)
	{
		res[i] = *s;
		i++;
		s++;
	}
	res[i] = '\0';
	return (res);
}

static int	ft_count_words(char const *s, char c)
{
	int		word;
	int		count;

	word = 0;
	count = 0;
	while (*s != '\0')
	{
		if (word == 0 && *s != c)
		{
			word = 1;
			count++;
		}
		if (word == 1 && *s == c)
			word = 0;
		s++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		n_words;
	int		j;

	if (s == 0)
		return (NULL);
	n_words = ft_count_words(s, c);
	res = (char **)malloc(sizeof(*res) * (n_words + 1));
	if (res == 0)
		return (0);
	j = 0;
	while (n_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		res[j] = ft_wrd(s, ft_word_len(s, c) + 1);
		s = s + ft_word_len(s, c);
		j++;
	}
	res[j] = 0;
	return (res);
}
