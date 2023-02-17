/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:59:20 by tgellon           #+#    #+#             */
/*   Updated: 2022/11/21 12:22:53 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*MAN : The bzero() function writes n zeroed bytes to the string s.  If n is
	zero, bzero() does nothing.*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
