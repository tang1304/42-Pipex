/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:02:11 by tgellon           #+#    #+#             */
/*   Updated: 2022/11/21 12:24:23 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* MAN : The memchr() function locates the first occurrence of c (converted
     to an unsigned char) in string s.*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char )c)
			return (&((unsigned char *)s)[i]);
		else
			i++;
	}
	return (NULL);
}
