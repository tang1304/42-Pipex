/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:51:01 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/16 14:39:46 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	data_init(t_pipex *pipex, int argc, char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		pipex->here_doc = 1;
	else
		pipex->here_doc = 0;
	pipex->input = -2;
	pipex->output = -2;
	pipex->cmd_nbr = argc - 3 - pipex->here_doc;
	pipex->pipe_nbr = (pipex->cmd_nbr - 1) * 2;
	pipex->children = malloc(sizeof(int) * pipex->pipe_nbr);
	if (pipex->children == NULL)
		ft_perror("Malloc error");
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
	free(pipex->children);
}

void	close_parents(t_pipex *pipex)
{
	if (pipex->input != -1)
		close(pipex->input);
	if (pipex->output != -1)
		close(pipex->output);
	close(pipex->pipes[0]);
	close(pipex->pipes[1]);
	// close (STDIN_FILENO);
	// close (STDOUT_FILENO);
}
