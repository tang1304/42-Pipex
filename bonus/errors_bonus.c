/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:50:41 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/22 17:05:17 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	pre_check_cmd_error(t_pipex *pipex)
{
	free(pipex->children);
	free_split(pipex->paths);
	close_all(pipex);
	exit(EXIT_FAILURE);
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
	free(pipex->children);
	free_split(cmd_args);
	free_split(pipex->paths);
	write(2, "Execve error\n", 13);
	exit(EXIT_FAILURE);
}
