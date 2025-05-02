/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:34:42 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/05/02 12:38:43 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	has_double(int l, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (i < l)
	{
		j = 0;
		while (j < l)
		{
			if (str[j] == str[i] && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6), i + 6);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_nbrbase(unsigned long nbr, char *base)
{
	unsigned long	nb;
	int				bl;
	int				len;

	nb = nbr;
	bl = 0;
	len = 0;
	while (base[bl])
	{
		if (base[bl] == '-' || base[bl] == '+')
			return (0);
		bl++;
	}
	if (bl < 2 || has_double(bl, base))
		return (0);
	if (nb >= (unsigned long)bl)
		len += ft_nbrbase(nb / bl, base);
	len += ft_putchar(base[nb % bl]);
	return (len);
}
