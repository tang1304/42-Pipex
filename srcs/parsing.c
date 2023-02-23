/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:24:43 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/23 16:36:23 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **envp)
{
	char	*envp_path;
	char	**paths;
	int		i;

	i = -1;
	while (envp[++i])
	{
		envp_path = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
		if (envp_path != NULL)
			break ;
	}
	paths = ft_split(envp_path, ':');
	if (!paths)
		ft_perror("Malloc error");
	return (paths);
}

static void	join_path_and_cmd(t_pipex *pipex, char *cmd, char **cmd_args, int i)
{
	pipex->path = ft_strjoin_malloced(pipex->paths[i], "/");
	if (!pipex->path)
	{
		free_split(pipex->paths);
		ft_perror("malloc error");
	}
	cmd = ft_strjoin_malloced(pipex->path, cmd_args[0]);
	if (!cmd)
	{
		free_split(pipex->paths);
		free(pipex->path);
		ft_perror("malloc error");
	}
}

void	get_cmd(char *argv, char *cmd, t_pipex *pipex, char **envp)
{
	int		i;
	char	**cmd_args;

	i = -1;
	cmd_args = ft_split(argv, ' ');
	if (cmd_args)
		ft_perror("Malloc error");
	while (pipex->path[++i])
	{
		join_path_and_cmd(pipex, cmd, cmd_args, i);
		if (access(pipex->path, X_OK) == 0)
		{
			if (execve(pipex->path, cmd_args, envp) == -1)
				ft_perror("Exec error");
		}
		free(pipex->path);
	}
}
