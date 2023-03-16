/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:35:54 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/09 15:54:07 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	data_init(t_pipex *pipex)
{
	pipex->input = -2;
	pipex->output = -2;
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
	str = NULL;
}

void	free_split_from_i(char **str, int i)
{
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
	str = NULL;
}

void	free_all(t_pipex *pipex, char **cmd_args, char *cmd, int i)
{
	free_split(cmd_args);
	free_split_from_i(pipex->paths, i);
	free(cmd);
}

void	close_parents(t_pipex *pipex)
{
	if (pipex->input != -1)
		close(pipex->input);
	if (pipex->output != -1)
		close(pipex->output);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

void	close_all(t_pipex *pipex)
{
	if (pipex->input != -1)
		close(pipex->input);
	if (pipex->output != -1)
		close(pipex->output);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
}
