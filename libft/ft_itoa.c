/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:46:43 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/22 13:47:00 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_countdigits(long n)
{
	long	i;
	long	x;

	i = 1;
	x = n;
	if (n < 0)
	{
		x = x * -1;
		i += 1;
	}
	while (x >= 10)
	{
		x = x / 10;
		i++;
	}
	return (i);
}

static	void	fill_data(char *res, long x, long sign, long digits)
{
	int	i;

	i = 0;
	while (i < digits)
	{
		if (digits - i == 1 && sign == -1)
			res[digits - i - 1] = '-';
		else
			res[digits - i - 1] = x % 10 + 48;
		i++;
		x = x / 10;
	}
	res[digits] = '\0';
}

char	*ft_itoa(int n)
{
	long		x;
	long		sign;
	long		digits;
	char		*res;

	x = n;
	sign = 1;
	digits = ft_countdigits(x);
	res = malloc(digits + 1 * sizeof(char));
	if (! res)
		return (NULL);
	if (x < 0)
	{
		x *= -1;
		sign *= -1;
	}
	fill_data(res, x, sign, digits);
	return (res);
}
