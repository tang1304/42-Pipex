/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:39:54 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/28 09:56:58 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	get_cmd_error(t_pipex *pipex, char **cmd_args, char *path, int i)
{
	free_split(cmd_args);
	free_split_from_i(pipex->paths, i);
	free(path);
	//  if (pipex->file1_status == 1)
	// 	close(pipex->input);
	// if (pipex->file2_status == 1)
	// 	close(pipex->output);
	ft_perror("Cmd error");
}
