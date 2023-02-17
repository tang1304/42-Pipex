/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:35:50 by tgellon           #+#    #+#             */
/*   Updated: 2022/11/21 14:41:51 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t size)
{
	void	*dest;
	size_t	tot_size;

	if (size && nelem > SIZE_MAX / size)
		return (0);
	tot_size = nelem * size;
	dest = malloc(tot_size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, tot_size);
	return (dest);
}
