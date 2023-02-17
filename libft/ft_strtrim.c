/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:55:02 by tgellon           #+#    #+#             */
/*   Updated: 2022/11/21 15:00:56 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
This function allocate and return a copy of string "s1", without the specified
characters in string "set" at the begining and end.
*/

#include "libft.h"

static int	ft_char_is_in(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*dest;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_char_is_in(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_is_in(s1[end - 1], set))
		end--;
	dest = malloc(sizeof(*s1) * (end - start + 1));
	if (!dest)
		return (NULL);
	while (start < end)
	{
		dest[i] = s1[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
