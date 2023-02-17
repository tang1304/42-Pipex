/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:48:46 by tgellon           #+#    #+#             */
/*   Updated: 2022/11/21 12:42:14 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* MAN : The strdup() function allocates sufficient memory for a copy of the
     string s1, does the copy, and returns a pointer to it.*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const char	*dest;
	size_t		size;

	size = ft_strlen(s) + 1;
	dest = malloc(sizeof(const char) * size);
	if (!dest)
		return (NULL);
	ft_strlcpy((char *)dest, s, size);
	return ((char *)dest);
}
