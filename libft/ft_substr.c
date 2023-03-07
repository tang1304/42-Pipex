/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:08:18 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/06 15:43:29 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* Allocate and return a new string from '*s', starting on index "start" and
   that has a maximum length of "len"*/

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	char	*temp;
	size_t	i;

	temp = ft_strdup(s);
	if (!s || !temp)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		dest = (char *)malloc(sizeof(const char) * (ft_strlen(s) - start + 1));
	else if (len + start > ft_strlen (s))
		dest = (char *)malloc(sizeof(const char) * (len));
	else
		dest = (char *)malloc(sizeof(const char) * (len + 1));
	if (!dest)
		return (free(temp), NULL);
	i = -1;
	while (++i < len && s[start])
	{
		dest[i] = s[start];
		start++;
	}
	dest[i] = '\0';
	return (free(temp), dest);
}
