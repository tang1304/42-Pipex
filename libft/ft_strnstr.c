/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:24:35 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/14 17:32:47 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* MAN : The strnstr() function locates the first occurrence of the null-
     terminated string little in the string big, where not more
     than len characters are searched.  Characters that appear after a
     `\0' character are not searched.*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if ((!big || !little) && len == 0)
		return (NULL);
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (little[j] == big[i] && little[j] && i < len)
		{
			j++;
			i++;
		}
		if (little[j] == '\0')
			return (&((char *)big)[i - j]);
		j = 0;
		k++;
		i = k;
	}
	return (NULL);
}
