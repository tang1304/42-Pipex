/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:10:15 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/24 10:20:25 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	get_hd_input(t_pipex *pipex, char **argv)
{
	char	*line;
	size_t	len;

	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		line = get_next_line(STDIN_FILENO, argv[2]);
		if (!line)
		{
			free(pipex->children);
			return ;
		}
		len = ft_strlen(line) - 1;
		if ((ft_strncmp(line, argv[2], len) == 0) \
			&& (ft_strlen(argv[2]) == len))
		{
			close(pipex->pipes[0]);
			close(pipex->pipes[1]);
			free(line);
			free(pipex->children);
			exit(EXIT_FAILURE);
		}
		ft_putstr_fd(line, pipex->pipes[1]);
		free(line);
	}
}

static void	pipe_and_fork(t_pipex *pipex, char **argv)
{
	int	hd_pid;

	if (pipe(pipex->pipes) == -1)
	{
		free(pipex->children);
		ft_perror("Pipe error");
	}
	hd_pid = fork();
	if (hd_pid == -1)
	{
		free(pipex->children);
		ft_perror("Fork error");
	}
	if (hd_pid == 0)
		get_hd_input(pipex, argv);
	waitpid(hd_pid, NULL, 0);
}

void	here_doc_init(t_pipex *pipex, char **argv, int argc)
{
	if (argc < 6)
	{
		free(pipex->children);
		ft_putendl_fd(ARGS_ERROR, 2);
		exit(EXIT_FAILURE);
	}
	pipe_and_fork(pipex, argv);
	if (dup2(pipex->pipes[0], STDIN_FILENO) == -1)
	{
		close_fds(pipex);
		free(pipex->children);
		ft_perror("Dupe error");
	}
	close(pipex->pipes[0]);
	close(pipex->pipes[1]);
}
