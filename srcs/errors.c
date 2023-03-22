/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:39:54 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/22 08:56:51 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	dup2_error(t_pipex *pipex)
{
	close_fds(pipex);
	free_split(pipex->paths);
	ft_perror("Dup error");
}

void	get_cmd_error(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	write(2, ": command not found\n", 20);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	directory_error(char *str)
{
	ft_putstr_fd(str, 2);
	write(2, ": Is a directory\n", 17);
	exit(EXIT_FAILURE);
}

void	execve_error(t_pipex *pipex, char **cmd_args)
{
	free_split(cmd_args);
	free_split(pipex->paths);
	write(2, "Execve error\n", 13);
	exit(EXIT_FAILURE);
}
