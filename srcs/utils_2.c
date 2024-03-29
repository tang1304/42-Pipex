/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:16:14 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/22 10:16:42 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	in_out_close(t_pipex *pipex)
{
	if (pipex->input != -1 && pipex->input != -2)
		close(pipex->input);
	if (pipex->output != -1 && pipex->output != -2)
		close(pipex->output);
}

void	close_fds(t_pipex *pipex)
{
	in_out_close(pipex);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

void	close_all(t_pipex *pipex)
{
	close_fds(pipex);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}
