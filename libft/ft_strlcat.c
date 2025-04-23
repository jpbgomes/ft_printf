/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:17:54 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/14 17:09:48 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long			src_l;
	unsigned long			dst_l;
	unsigned long			i;

	i = 0;
	src_l = ft_strlen(src);
	dst_l = ft_strlen(dst);
	if (dst_l >= size)
		return (src_l + size);
	while (src[i] && (dst_l + i + 1 < size))
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	dst[dst_l + i] = '\0';
	return (dst_l + src_l);
}
