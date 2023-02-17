/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:26:04 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/26 14:00:22 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_typecheck(char c)
{
	if (c == 'c' || c == 's' || c == 'i'
		|| c == 'd' || c == 'u' || c == 'X'
		|| c == 'x' || c == 'p' || c == '%')
		return (1);
	else
		return (0);
}

static int	ft_type(const char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 's')
		i += ft_printstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		i += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		i += ft_printunbr(va_arg(args, unsigned int));
	else if (c == 'X')
		i += ft_printnbr_base(va_arg(args, unsigned int), HEX_BASE_UPPER);
	else if (c == 'x')
		i += ft_printnbr_base(va_arg(args, unsigned int), HEX_BASE_LOWER);
	else if (c == 'p')
	{
		i += write(1, "0x", 2);
		i += ft_printnbr_p(va_arg(args, unsigned long), HEX_BASE_LOWER);
	}
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len_printed;

	if (write(1, 0, 0) == -1)
		return (-1);
	i = 0;
	len_printed = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_typecheck(str[i + 1]))
			{
				len_printed += ft_type(str[i + 1], args);
				i++;
			}
		}
		else
			len_printed += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len_printed);
}
