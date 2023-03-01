/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:24:43 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/01 10:33:51 by tgellon          ###   ########lyon.fr   */
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
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			envp_path = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
			if (envp_path != NULL)
				break ;
		}
	}
	paths = ft_split(envp_path + 5, ':');
	if (paths == NULL)
		ft_perror("Malloc error");
	return (paths);
}

static void	join_path_and_cmd(t_pipex *pipex, char *cmd, int i)
{
	pipex->path = ft_strjoin_malloced(pipex->paths[i], cmd);
	if (pipex->path == NULL)
	{
		free_split(pipex->paths);
		ft_perror("malloc error");
	}
}

static void	check_if_absolute_path(t_pipex *pipex, char *argv, \
									char **cmd_args, char **envp)
{
	if (access(cmd_args[0], X_OK) == 0)
	{
		if (execve(cmd_args[0], cmd_args, envp) == -1)
			ft_perror("Exec error");
	}
	free_split(cmd_args);
	free_split(pipex->paths);
	get_cmd_error(argv);
}

void	get_cmd(char *argv, t_pipex *pipex, char **cmd_args, char **envp)
{
	int		i;
	char	*tmp;

	i = -1;
	cmd_args = ft_split(argv, ' ');
	if (cmd_args == NULL)
		ft_perror("Malloc error");
	if (ft_strchr(cmd_args[0], '/') != NULL)
		check_if_absolute_path(pipex, argv, cmd_args, envp);
	tmp = ft_strjoin("/", cmd_args[0]);
	if (tmp == NULL)
		ft_perror("Malloc error");
	while (pipex->paths[++i])
	{
		join_path_and_cmd(pipex, tmp, i);
		if (access(pipex->path, X_OK) == 0)
		{
			if (execve(pipex->path, cmd_args, envp) == -1)
				ft_perror("Exec error");
		}
		free(pipex->path);
	}
	free_all(pipex, cmd_args, tmp, i);
	get_cmd_error(argv);
}
