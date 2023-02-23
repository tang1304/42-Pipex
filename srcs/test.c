/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:04:50 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/22 15:10:05 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "stdio.h"

int	main(int argc, char ** argv, char **envp)
{
	(void)argc;
	(void)argv;
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}