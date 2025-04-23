/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:59:07 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/14 17:09:48 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		if (i < ft_strlen(s1))
			tmp[i] = s1[i];
		else
			tmp[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
