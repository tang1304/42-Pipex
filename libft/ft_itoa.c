/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:28:11 by tgellon           #+#    #+#             */
/*   Updated: 2022/11/18 15:29:51 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*dest_filler(char *dest, int i, int len, int n)
{
	dest[len] = '\0';
	if (n < 0 && n > -2147483648)
	{
		dest[0] = '-';
		n *= -1;
		i++;
	}
	if (n == -2147483648)
	{
		dest[0] = '-';
		dest[len - 1] = 8 + '0';
		n /= 10;
		n *= -1;
		len--;
		i++;
	}
	while (len > i)
	{
		len--;
		dest[len] = (n % 10) + '0';
		n /= 10;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = nbrlen(n);
	if (n <= 0)
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest_filler(dest, i, len, n);
	return (dest);
}
