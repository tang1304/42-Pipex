/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:15:24 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/06 15:45:21 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (dest = ft_strdup(s2));
	if (!s2)
		return (dest = ft_strdup(s1));
	dest = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_read(int fd, char *stock)
{
	int		i;
	char	*str;
	char	*temp;

	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
			return (free(stock), free(str), NULL);
		str[i] = '\0';
		temp = stock;
		stock = ft_strjoin_gnl(temp, str);
		if (!stock)
			return (free(str), NULL);
		free(temp);
		if (ft_strchr_gnl(stock, '\n'))
			break ;
	}
	return (free(str), stock);
}

static char	*ft_get_str(char *stock)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] != '\n' && stock[i])
		i++;
	if (stock[i] == '\n')
		i++;
	newstr = ft_calloc(i + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (j < i)
	{
		newstr[j] = stock[j];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}

static char	*ft_clear(char *stock)
{
	size_t	i;
	size_t	j;
	char	*new_stock;

	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	new_stock = ft_calloc((ft_strlen(stock) - i + 1), sizeof(char));
	if (!new_stock)
		return (NULL);
	j = 0;
	while (stock[i])
	{
		new_stock[j] = stock[i + 1];
		i++;
		j++;
	}
	new_stock[j] = '\0';
	free(stock);
	return (new_stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stock)
		stock = ft_calloc(1, 4);
	stock = ft_read(fd, stock);
	if (!stock)
	{
		free (stock);
		return (NULL);
	}
	line = ft_get_str(stock);
	// if (!line)
	// 	return (free(stock), NULL);
	stock = ft_clear(stock);
	return (line);
}
