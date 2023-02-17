/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:28:19 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/10 08:48:17 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (nb);
}

static int	ft_word_size(const char *s, char c, int i)
{
	int	nb;

	nb = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		nb++;
	}
	return (nb);
}

static void	ft_free(char **c, int j)
{
	while (j > 0)
	{
		free(c[j]);
		j--;
	}
	free(c);
}

static char	**ft_sub_split(char **dest, const char *s, char c, int size)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (s[i] == c)
			i++;
		len = ft_word_size(s, c, i);
		dest[j] = ft_substr(s, i, len);
		if (!dest[j])
		{
			ft_free(dest, j);
			return (NULL);
		}
		i += len;
		j++;
	}
	dest[j] = 0;
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**dest;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	dest = (char **)malloc(sizeof(char *) * (size + 1));
	if (!dest)
		return (NULL);
	if (!ft_sub_split(dest, s, c, size))
		return (NULL);
	return (dest);
}
