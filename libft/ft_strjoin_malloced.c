/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_malloced.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:48:29 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/01 11:09:44 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_malloced(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (dest = ft_strdup(s2));
	if (!s2)
		return (dest = s1);
	dest = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!dest)
		return (free(s1), NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
	{
		dest[i] = s2[j];
		i++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}
