/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:29:38 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/05/02 16:25:47 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int	ft_checkparameter(va_list args, char c)
{
	int		total_len;
	void	*ptr;

	total_len = 0;
	if (c == 'c')
		total_len += ft_putchar((char)va_arg(args, int));
	if (c == 's')
		total_len += ft_putstr((char *)va_arg(args, char *));
	if (c == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			total_len += ft_putstr("(nil)");
		else
		{
			total_len += ft_putstr("0x");
			total_len += ft_nbrbase((unsigned long)ptr, "0123456789abcdef");
		}
	}
	return (total_len);
}

int	ft_checkparameter2(va_list args, char c)
{
	int		total_len;
	int		nbr;
	long	nb;

	total_len = 0;
	if (c == 'd' || c == 'i')
	{
		nbr = (int)va_arg(args, int);
		nb = nbr;
		if (nb < 0)
		{
			total_len += ft_putchar('-');
			nb = -nb;
		}
		total_len += ft_nbrbase((unsigned int)nb, "0123456789");
	}
	return (total_len);
}

int	ft_checkparameter3(va_list args, char c)
{
	int	total_len;

	total_len = 0;
	if (c == 'u')
		total_len += ft_nbrbase((unsigned long)
				va_arg(args, unsigned int), "0123456789");
	if (c == 'x')
		total_len += ft_nbrbase((unsigned int)(int)
				va_arg(args, int), "0123456789abcdef");
	if (c == 'X')
		total_len += ft_nbrbase((unsigned int)(int)
				va_arg(args, int), "0123456789ABCDEF");
	if (c == '%')
		total_len += ft_putchar(c);
	return (total_len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		total_len;
	int		i;

	total_len = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && is_valid(s[i + 1]))
		{
			i++;
			total_len += ft_checkparameter(args, s[i]);
			total_len += ft_checkparameter2(args, s[i]);
			total_len += ft_checkparameter3(args, s[i]);
		}
		else
			total_len += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (total_len);
}
