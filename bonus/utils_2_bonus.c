/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:12:27 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/22 10:28:27 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_fds(t_pipex *pipex)
{
	if (pipex->input != -1 && pipex->input != -2)
		close(pipex->input);
	if (pipex->output != -1 && pipex->output != -2)
		close(pipex->output);
	close(pipex->pipes[0]);
	close(pipex->pipes[1]);
}

void	close_all(t_pipex *pipex)
{
	close_fds(pipex);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}
