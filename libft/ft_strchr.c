/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:19:57 by tgellon           #+#    #+#             */
/*   Updated: 2022/11/29 14:44:36 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*MAN : The strchr() function locates the first occurrence of c (converted
     to a char) in the string pointed to by s.  The terminating null
     character is considered to be part of the string; therefore if c is
     `\0', the functions locate the terminating `\0'.
	 It returns a pointer to this char */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}
