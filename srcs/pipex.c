/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:55:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/24 16:56:12 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_command(char **argv, char **envp, t_pipex *pipex)
{
	(void)argv;
	(void)envp;

	if (dup2(pipex->fd[1], STDOUT_FILENO) == -1)
		ft_perror("Dup error");
	if (dup2(pipex->input, STDIN_FILENO) == -1)
		ft_perror("Dup error");
	close(pipex->fd[0]);//
	close(pipex->input);
	close(pipex->fd[1]);//closed the 2 fds of the child cause it is now in stdout
	get_cmd(argv[2], pipex, pipex->cmd1, envp);
}

static void	second_command(char **argv, char **envp, t_pipex *pipex)
{
	if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
		ft_perror("dup error");
	if (dup2(pipex->output, STDOUT_FILENO) == -1)
		ft_perror("Dup error");
	close(pipex->fd[1]);//closed the 2 fds of the child cause it is now in stdin
	close(pipex->output);
	close(pipex->fd[0]);//
	get_cmd(argv[3], pipex, pipex->cmd2, envp);
}

static void	open_files(t_pipex *pipex, char *file1, char *file2)
{
	pipex->input = open(file1, O_RDONLY);
	if (pipex->input == -1)
		ft_perror("Opening error");
	pipex->output = open(file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->output == -1)
		ft_perror("Opening Error");
}

static void	close_parents(t_pipex *pipex)
{
	close(pipex->input);
	close(pipex->output);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_error(ARGS_ERROR);
	open_files(&pipex, argv[1], argv[4]);
	pipex.paths = get_paths(envp);
	if (pipe(pipex.fd) == -1)
	{
		free_split(pipex.paths);
		ft_perror("Pipe error");
	}
	pipex.pid1 = fork();//creates first child for the first cmd
	if ((pipex.pid1 == -1))
		ft_perror("PID error");
	if (pipex.pid1 == 0)// child 1 process
		first_command(argv, envp, &pipex);
	pipex.pid2 = fork();//creates 2nd child for the 2nd cmd
	if (pipex.pid2 == -1)
		ft_perror("PID error");
	if (pipex.pid2 == 0)//child 2 process
		second_command(argv, envp, &pipex);
	close_parents(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_split(pipex.paths);
}




































/*
char	**find_path(char **envp)
{
	char **tab;

	tab = NULL;
	for (int i = 0; envp[i]; i++)
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
			tab = ft_split(ft_strnstr(envp[i], "/", ft_strlen(envp[i])), ':');
	}
	return (tab);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid, pid2;
	int	fd_in;
	int	fd_out;
	char	**tab;
	char	**path;
	char	*str;

	path = find_path(envp);
	pipe(fd);
	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777); // fd_out
	pid = fork();
	if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
			tab = ft_split(argv[2], ' ');
			for (int k = 0; path[k]; k++)
			{
				str = ft_strjoin(path[k], tab[0]);
				if (access(str, X_OK) == 0)
					execve(str, tab, envp);
				free(str);
			}
			exit(0);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		//dup2(fd_out, STDOUT_FILENO); //la redirection de stdout vers fd_out ne marche pas
		tab = ft_split(argv[3], ' ');
			for (int k = 0; path[k]; k++)
			{
				str = ft_strjoin(path[k], tab[0]);
				if (access(str, X_OK) == 0)
					execve(str, tab, envp);
				free(str);
			}
			exit(0);
	}
	return (0);
}*/