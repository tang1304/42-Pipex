/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:29:05 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/31 09:22:03 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*MAN : The strrchr() function locates the last occurrence of c (converted
     to a char) in the string pointed to by s.  The terminating null
     character is considered to be part of the string; therefore if c is
     `\0', the functions locate the terminating `\0'.*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		else
			i--;
	}
	return (NULL);
}
