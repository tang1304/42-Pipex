/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:50:41 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/14 10:52:18 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	get_cmd_error(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": command not found", 2);
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
