/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:55:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/01 11:04:26 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_command(char **argv, char **envp, t_pipex *pipex)
{
	pipex->pid1 = fork();//creates first child for the first cmd
	if ((pipex->pid1 == -1))
		ft_perror("PID error");
	if (pipex->pid1 == 0)// child 1 process
	{
		if (pipex->input == -1)
		{
			close_parents(pipex);
			free_split(pipex->paths);
			exit(EXIT_FAILURE);
		}
		if (dup2(pipex->pipe[1], STDOUT_FILENO) == -1)
			ft_perror("Dup error");
		if (dup2(pipex->input, STDIN_FILENO) == -1)
			ft_perror("Dup error");
		close_parents(pipex);
		get_cmd(argv[2], pipex, pipex->cmd1, envp);
	}
}

static void	second_command(char **argv, char **envp, t_pipex *pipex)
{
	pipex->pid2 = fork();//creates 2nd child for the 2nd cmd
	if (pipex->pid2 == -1)
		ft_perror("PID error");
	if (pipex->pid2 == 0)//child 2 process
	{
		if (pipex->output == -1)
		{
			close_parents(pipex);
			free_split(pipex->paths);
			exit(EXIT_FAILURE);
		}
		if (dup2(pipex->pipe[0], STDIN_FILENO) == -1)
			ft_perror("dup error");
		if (dup2(pipex->output, STDOUT_FILENO) == -1)
			ft_perror("Dup error");
		close_parents(pipex);
		get_cmd(argv[3], pipex, pipex->cmd2, envp);
	}
}

static void	open_files(t_pipex *pipex, char *file1, char *file2)
{
	pipex->input = open(file1, O_RDONLY);
	if (pipex->input == -1)
		perror(file1);
	pipex->output = open(file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->output == -1)
		perror(file2);
}

static void	data_init(t_pipex *pipex)
{
	pipex->input = -2;
	pipex->output = -2;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_error(ARGS_ERROR);
	data_init(&pipex);
	open_files(&pipex, argv[1], argv[4]);
	pipex.paths = get_paths(envp);
	if (pipe(pipex.pipe) == -1)
	{
		free_split(pipex.paths);
		ft_perror("Pipe error");
	}
	first_command(argv, envp, &pipex);
	second_command(argv, envp, &pipex);
	close_parents(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_split(pipex.paths);
}
