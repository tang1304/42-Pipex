/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:28:54 by tgellon           #+#    #+#             */
/*   Updated: 2022/11/21 12:39:06 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
MAN ; The memset() function writes len bytes of value c (converted to an
     unsigned char) to the string b.
str − This is a pointer to the block of memory to fill.
c − This is the value to be set. The value is passed as an int, but the function
fills the block of memory using the unsigned char conversion of this value.
n − This is the number of bytes to be set to the value.
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
