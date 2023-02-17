/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:38:19 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/25 08:42:14 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *str)
{
	size_t	i;
	size_t	j;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	j = 0;
	while (str[j])
	{
		i += ft_putchar(str[j]);
		j++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	size_t		i;
	long int	nbr;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		i += ft_printnbr(nbr / 10);
		i += ft_printnbr(nbr % 10);
	}
	else
		i += ft_putchar(nbr + 48);
	return (i);
}

int	ft_printunbr(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n > 9)
	{
		i += ft_printnbr(n / 10);
		i += ft_printnbr(n % 10);
	}
	else
		i += ft_putchar(n + 48);
	return (i);
}

int	ft_printnbr_base(unsigned int nbr, char *base)
{
	size_t	i;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_printnbr_base(nbr / 16, base);
		i += ft_printnbr_base(nbr % 16, base);
	}
	else if (nbr > 9)
		i += ft_putchar(nbr[base]);
	else
		i += ft_putchar(nbr[base]);
	return (i);
}

unsigned int	ft_printnbr_p(unsigned long n, char *base)
{
	size_t	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_printnbr_p(n / 16, base);
		i += ft_printnbr_p(n % 16, base);
	}
	else if (n > 9)
		i += ft_putchar(n[base]);
	else
		i += ft_putchar(n[base]);
	return ((unsigned int)i);
}
