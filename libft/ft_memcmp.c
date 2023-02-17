/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:36:39 by tgellon           #+#    #+#             */
/*   Updated: 2022/11/21 12:25:40 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* MAN : The memcmp() function compares byte string s1 against byte string
     s2.  Both strings are assumed to be n bytes long.*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (us1[i] == us2[i] && i < n - 1)
		i++;
	return (us1[i] - us2[i]);
}
