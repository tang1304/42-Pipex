/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:43:48 by tgellon           #+#    #+#             */
/*   Updated: 2022/11/23 11:11:15 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	if (size == 0 && (!dest || !src))
		return (0);
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	while (src[i] && (len_dest + i < size - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	if (i < size)
		dest[len_dest + i] = '\0';
	if (len_dest > size)
		return (len_src + size);
	else
		return (len_dest + len_src);
}
