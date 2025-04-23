/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:25:23 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/22 14:40:32 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	wc;
	int	going;

	i = 0;
	wc = 0;
	going = 1;
	while (s[i])
	{
		if (s[i] != c && going)
			wc++;
		going = 0;
		if (s[i] == c)
			going = 1;
		i++;
	}
	return (wc);
}

static int	ft_wordlen(char const *s, int start, char c)
{
	int	i;

	i = start;
	while (s[i] && s[i] != c)
		i++;
	return (i - start);
}

static char	**free_data(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	**insert_data(char **res, int wc, const char *s, char c)
{
	int	j;
	int	i;
	int	start;
	int	count;

	j = 0;
	i = 0;
	while (j < wc)
	{
		count = 0;
		if (s[i] != c)
		{
			start = i;
			count = ft_wordlen(s, i, c);
			res[j] = (char *)malloc(sizeof(char) * (count + 1));
			if (!res[j])
				return (free_data(res));
			ft_strlcpy(res[j++], s + start, count + 1);
		}
		else
			i++;
		i = i + count;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = ft_calloc((ft_countwords(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	res = insert_data(res, ft_countwords(s, c), s, c);
	return (res);
}
