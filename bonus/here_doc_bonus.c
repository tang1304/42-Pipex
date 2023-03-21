/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:10:15 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/20 15:53:51 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	get_hd_input(t_pipex *pipex, char **argv)
{
	char	*line;
	size_t	len;

	while (1)
	{
		ft_putstr_fd("> ", 2);
		line = get_next_line(STDIN_FILENO);
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
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, pipex->pipes[1]);
		free(line);
	}
}

void	here_doc_init(t_pipex *pipex, char **argv, int argc)
{
	int	hd_pid;

	if (argc < 6)
	{
		free(pipex->children);
		ft_error(HERE_DOC_ARGS_ERROR);
	}
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
	if (dup2(pipex->pipes[0], STDIN_FILENO) == -1)
	{
		free(pipex->children);
		ft_perror("Fork error");
	}
	close(pipex->pipes[0]);
	close(pipex->pipes[1]);
}
