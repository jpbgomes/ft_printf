/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:29:38 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/05/02 12:23:22 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	is_valid(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

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

static int	ft_putnbr_base(unsigned long nbr, char *base)
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
		len += ft_putnbr_base(nb / bl, base);
	len += ft_putchar(base[nb % bl]);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list args;
	int total_len;
	int	i;

	total_len = 0;
	i = 0;

	va_start(args, s);
	while(s[i])
	{
		if (s[i] == '%' && is_valid(s[i + 1]))
		{
			i++;

			if (s[i] == 'c')
			{
				char c = (char)va_arg(args, int);
				total_len += ft_putchar(c);
			}

			if (s[i] == 's')
			{
				char *str = (char *)va_arg(args, char *);
				total_len += ft_putstr(str);
			}

			if (s[i] == 'p')
			{
				void *ptr = va_arg(args, void *);
				if (ptr == NULL)
					total_len += ft_putstr("(nil)");
				else
				{
					total_len += ft_putstr("0x");
					total_len += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
				}
			}

			if (s[i] == 'd' || s[i] == 'i')
			{
				int nbr = (int)va_arg(args, int);
				long nb = nbr;
				if (nb < 0)
				{
					total_len += ft_putchar('-');
					nb = -nb;
				}
				total_len += ft_putnbr_base((unsigned int)nb, "0123456789");
			}

			if (s[i] == 'u')
			{
				unsigned int nbr = va_arg(args, unsigned int);
				total_len += ft_putnbr_base((unsigned long)nbr, "0123456789");
			}

			if (s[i] == 'x')
			{
				int nbr = (int)va_arg(args, int);
				total_len += ft_putnbr_base((unsigned int)nbr, "0123456789abcdef");
			}

			if (s[i] == 'X')
			{
				int nbr = (int)va_arg(args, int);
				total_len += ft_putnbr_base((unsigned int)nbr, "0123456789ABCDEF");
			}

			if (s[i] == '%')
			total_len += ft_putchar(s[i]);
		}
		else
		total_len += ft_putchar(s[i]);

		i++;
	}
	va_end(args);

	return (total_len);
}
