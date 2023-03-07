/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_selection_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:30:40 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/07 16:00:52 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	first_command(t_pipex *pipex, int *fd)
{
	if (pipex->input == -1)
	{
		close_parents(pipex);
		free_split(pipex->paths);
		if (pipex->here_doc)
		{
			;
		}
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_perror("Dup error");
}

void	command_init(char *argv, char **envp, t_pipex *pipex)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
	{
		free_split(pipex->paths);
		ft_perror("Pipe error");
	}
	pid = fork();
	if ((pid == -1))
		ft_perror("Fork error");
	if (pid != 0)
		return ;
	if ((pipex->here_doc == 0 && pipex->cmd == 2) \
		|| (pipex->here_doc == 1 && pipex->cmd == 3))
		first_command(pipex, fd);
	else if (pipex->cmd == pipex->cmd_nbr - 1)
		last_command(pipex, fd);
	else
	{
		if (pipex->input == -1)
		{
			close_parents(pipex);
			free_split(pipex->paths);
			exit(EXIT_FAILURE);
		}
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_perror("Dup error");
		close(fd[1]);
		// close_parents(pipex);
		get_cmd(argv, pipex, envp);
	}
}
