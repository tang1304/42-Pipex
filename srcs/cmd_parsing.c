/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:24:43 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/24 11:36:43 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	join_path_and_cmd(t_pipex *pipex, char *cmd, int i)
{
	pipex->path = ft_strjoin_malloced(pipex->paths[i], cmd);
	if (pipex->path == NULL)
	{
		free_split(pipex->paths);
		ft_perror("malloc error");
	}
}

static void	check_if_absolute_path(t_pipex *pipex, \
									char **cmd_args, char **envp)
{
	int	fd;

	if ((cmd_args[0][0] == '.' && cmd_args[0][1] == '/' && \
		!ft_isalnum(cmd_args[0][2])) || (cmd_args[0][0] == '/' && \
			(!ft_isalnum(cmd_args[0][1]) || cmd_args[0][1] == '/')))
	{
		write(2, cmd_args[0], ft_strlen(cmd_args[0]));
		write(2, ": Is a directory\n", 18);
		free_split(cmd_args);
		pre_check_cmd_error(pipex);
	}
	fd = open(cmd_args[0], O_RDONLY);
	if (fd == -1 || access(cmd_args[0], X_OK))
	{
		perror(cmd_args[0]);
		free_split(cmd_args);
		pre_check_cmd_error(pipex);
	}
	if (execve(cmd_args[0], cmd_args, envp) == -1)
	{
		close(fd);
		execve_error(pipex, cmd_args);
	}
}

static void	pre_check_on_cmd(t_pipex *pipex, char *argv)
{
	if (argv[0] == '\0')
	{
		write(2, "Command '' not found\n", 21);
		pre_check_cmd_error(pipex);
	}
	if (argv[0] == '.' && !argv[1])
	{
		write(2, ".: filename argument required\n", 30);
		write(2, ".: usage: . filename [arguments]\n", 33);
		pre_check_cmd_error(pipex);
	}
}

static void	loop_on_path(t_pipex *pipex, char **cmd_args, char **envp)
{
	int		i;
	char	*cmd;

	i = -1;
	cmd = ft_strjoin("/", cmd_args[0]);
	if (cmd == NULL)
	{
		free_split(cmd_args);
		free_split(pipex->paths);
		ft_perror("Malloc error");
	}
	while (pipex->paths[++i])
	{
		join_path_and_cmd(pipex, cmd, i);
		if (access(pipex->path, X_OK) == 0)
		{
			if (execve(pipex->path, cmd_args, envp) == -1)
				execve_error(pipex, cmd_args);
		}
		free(pipex->path);
	}
	free_all(pipex, cmd_args, cmd, i);
}

void	get_cmd(char *argv, t_pipex *pipex, char **cmd_args, char **envp)
{
	pre_check_on_cmd(pipex, argv);
	cmd_args = ft_split(argv, ' ');
	if (cmd_args == NULL)
	{
		free_split(pipex->paths);
		ft_perror("Malloc error");
	}
	if (cmd_args[0] == NULL)
	{
		free_split(cmd_args);
		free_split(pipex->paths);
		get_cmd_error(argv);
	}
	if (ft_strchr(cmd_args[0], '/') != NULL)
		check_if_absolute_path(pipex, cmd_args, envp);
	loop_on_path(pipex, cmd_args, envp);
	get_cmd_error(argv);
}
