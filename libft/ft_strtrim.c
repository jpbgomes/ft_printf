/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:10:46 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/16 16:20:02 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contains(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		s;
	int		e;
	char	*tmp;

	if (! s1 || ! set)
		return (NULL);
	i = 0;
	s = 0;
	e = ft_strlen(s1);
	while (s1[s] && ft_contains((char *)set, s1[s]))
		s++;
	while (e > s && ft_contains((char *)set, s1[e - 1]))
		e--;
	tmp = malloc(e - s + 1);
	if (tmp == NULL)
		return (NULL);
	while (i < e - s)
	{
		tmp[i] = s1[s + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
