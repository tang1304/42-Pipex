/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:55:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/17 17:09:24 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)envp;
	int	fd[2];
	int	pid1;
	int	pid2;
//	char **path;

	if (argc != 5)
		return (0);
//	path == ft_x(); //parsing fct
	if (pipe(fd) == -1)
		return (0);
	pid1 = fork();//creates first child for the first cmd
	if ((pid1 == -1))
		return (0);
	if (pid1 == 0)// child 1 process
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);//
		close(fd[1]);//closed the 2 fds of the child, cause it is now in stdout
		execlp("cat", "cat", "srcs/pipex.h", NULL);
	}
	pid2 = fork();//creates 2nd child for the 2nd cmd
	if (pid2 == -1)
		return (0);
	if (pid2 == 0)//child 2 process
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);//
		close(fd[1]);//closed the 2 fds of the child, cause it is now in stdin
		execlp("grep", "grep", "if", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
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