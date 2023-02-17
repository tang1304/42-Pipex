/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:11:40 by tgellon           #+#    #+#             */
/*   Updated: 2022/11/21 12:25:50 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*MAN : The memcpy() function copies n bytes from memory area src to memory
     area dst.  If dst and src overlap, behavior is undefined.  Applica-
     tions in which dst and src might overlap should use memmove(3)
     instead.*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == 0 && dest == 0)
		return (NULL);
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
