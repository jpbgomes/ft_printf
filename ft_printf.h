/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:20:46 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/05/02 12:39:41 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *s, ...);
int	has_double(int l, char *str);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_nbrbase(unsigned long nbr, char *base);
#endif
