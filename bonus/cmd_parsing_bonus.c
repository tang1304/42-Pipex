/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:50:49 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/07 14:56:04 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
			!ft_isalnum(cmd_args[0][1])))
	{
		write(2, cmd_args[0], ft_strlen(cmd_args[0]));
		write(2, ": Is a directory\n", 18);
		free_split(cmd_args);
		free_split(pipex->paths);
		exit(EXIT_FAILURE);
	}
	fd = open(cmd_args[0], O_RDONLY);
	if (fd == -1 || access(cmd_args[0], X_OK))
	{
		perror(cmd_args[0]);
		free_split(cmd_args);
		free_split(pipex->paths);
		exit(EXIT_FAILURE);
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
		free_split(pipex->paths);
		exit(EXIT_FAILURE);
	}
	if (argv[0] == '.' && !argv[1])
	{
		write(2, ".: filename argument required\n", 30);
		write(2, ".: usage: . filename [arguments]\n", 33);
		free_split(pipex->paths);
		exit(EXIT_FAILURE);
	}
}

static void	loop_on_path(t_pipex *pipex, char **cmd_args, \
							char **envp, char *cmd)
{
	int	i;

	i = -1;
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

void	get_cmd(char *argv, t_pipex *pipex, char **envp)
{
	char	*tmp;
	char	**cmd_args;

	pre_check_on_cmd(pipex, argv);
	cmd_args = ft_split(argv, ' ');
	if (cmd_args == NULL)
	{
		free_split(pipex->paths);
		ft_perror("Malloc error");
	}
	if (ft_strchr(cmd_args[0], '/') != NULL)
		check_if_absolute_path(pipex, cmd_args, envp);
	tmp = ft_strjoin("/", cmd_args[0]);
	if (tmp == NULL)
	{
		free_split(pipex->paths);
		free_split(cmd_args);
		ft_perror("Malloc error");
	}
	loop_on_path(pipex, cmd_args, envp, tmp);
	get_cmd_error(argv);
}
