/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:29:38 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/22 17:56:57 by jpedro-b         ###   ########.fr       */
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

static int	ft_countparams(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
			if (is_valid(s[i + 1]))
				count++;
		i++;
	}	

	return (count);
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

static void	ft_putnbr_base(unsigned long nbr, char *base)
{
	long	nb;
	int		bl;

	nb = nbr;
	bl = 0;
	while (base[bl])
	{
		if (base[bl] == '-' || base[bl] == '+')
			return ;
		bl++;
	}
	if (bl < 2 || has_double(bl, base))
		return ;
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb = -nb;
	}
	if (nb >= bl)
		ft_putnbr_base((nb / bl), base);
	ft_putchar_fd(base[nb % bl], 1);
}

int	ft_printf(const char *s, ...)
{
	va_list args;
	int	arg_num;
	int	i;

	i = 0;
	arg_num = ft_countparams(s);
	if (arg_num == 0)
		printf("\nPARAMETROS INVALIDOS\n");
	else
		printf("\nPARAMETROS = %d\n", arg_num);

	va_start(args, s);
	while(s[i])
	{
		if (s[i] == '%' && is_valid(s[i + 1]))
		{
			i++;

			if (s[i] == 'c')
			{
				char c = (char)va_arg(args, int);
				ft_putchar_fd(c, 1);
			}

			if (s[i] == 's')
			{
				char *str = (char *)va_arg(args, char *);
				ft_putstr_fd(str, 1);
			}

			if (s[i] == 'p')
			{
				void *ptr = (void *)va_arg(args, void *);
				ft_putstr_fd("0x", 1);
				ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
			}

			if (s[i] == 'd' || s[i] == 'i' || s[i] == 'u')
			{
				int nbr = (int)va_arg(args, int);
				ft_putnbr_base((unsigned long)nbr, "0123456789");
			}

			if (s[i] == 'x')
			{
				int nbr = (int)va_arg(args, int);
				ft_putnbr_base((unsigned long)nbr, "0123456789abcdef");
			}

			if (s[i] == 'X')
			{
				int nbr = (int)va_arg(args, int);
				ft_putnbr_base((unsigned long)nbr, "0123456789ABCDEF");
			}

			if (s[i] == '%')
				ft_putchar_fd(s[i], 1);
		}
		else
			ft_putchar_fd(s[i], 1);

		i++;
	}
	va_end(args);

	return (0);
}
