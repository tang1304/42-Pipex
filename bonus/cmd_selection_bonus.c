/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_selection_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:30:40 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/16 16:23:08 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	first_command(t_pipex *pipex)
{
	if (pipex->input == -1)
	{
		close_parents(pipex);
		free_split(pipex->paths);
		// if (pipex->here_doc)
		// {
		// 	;
		// }
		exit(EXIT_FAILURE);
	}
	close(pipex->pipes[0]);
	if (dup2(pipex->input, STDIN_FILENO) == -1)
	{
		free_split(pipex->paths);
		ft_perror("Dup error");
	}
	close(pipex->input);
	if (dup2(pipex->pipes[1], STDOUT_FILENO) == -1)
	{
		free_split(pipex->paths);
		ft_perror("Dup error");
	}
	close(pipex->pipes[1]);
}

static void	last_command(t_pipex *pipex)
{
	if (pipex->output == -1)
	{
		close_parents(pipex);
		free_split(pipex->paths);
		// if (pipex->here_doc)
		// {
		// 	;
		// }
		exit(EXIT_FAILURE);
	}
	close(pipex->pipes[0]);
	if (dup2(pipex->output, STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("ici\n", 2);
		close(STDIN_FILENO);
		close_parents(pipex);
		free_split(pipex->paths);
		ft_perror("Dup error");
	}
}

static void	middle_command(t_pipex *pipex)
{
	close(pipex->pipes[0]);
	if (dup2(pipex->pipes[1], STDOUT_FILENO) == -1)
		ft_perror("Dup error");
	close(pipex->pipes[1]);
}

static void	command_init(t_pipex *pipex, char **argv, char ** envp, int i)
{
	pipex->children[i] = fork();
	if ((pipex->children[i] == -1))
		ft_perror("Fork error");
	if (pipex->children[i] == 0)
	{
		if ((pipex->here_doc == 0 && pipex->cmd == 2) \
			|| (pipex->here_doc == 1 && pipex->cmd == 3))
			first_command(pipex);
		else if (pipex->cmd == pipex->cmd_nbr + 1)
			last_command(pipex);
		else
			middle_command(pipex);
		get_cmd(argv[pipex->cmd], pipex, envp);
	}
	else
		if (dup2(pipex->pipes[0], STDIN_FILENO) == -1)
		{
			free_split(pipex->paths);
			ft_perror("Dup error");
		}
	close(pipex->pipes[0]);
}

void	pipex_init(char **argv, char **envp, t_pipex *pipex)
{
	int	i;

	i = -1;
	while (++i < pipex->cmd_nbr)
	{
		if (pipe(pipex->pipes) == -1)
		{
			free_split(pipex->paths);
			ft_perror("Pipe error");
		}
		command_init(pipex, argv, envp, i);
		close(pipex->pipes[0]);
		close(pipex->pipes[1]);
		pipex->cmd++;
	}
	close_parents(pipex);
	while (waitpid(-1, NULL, 0) < 0)
		;
}
