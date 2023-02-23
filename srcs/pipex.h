/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:55:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/23 15:38:55 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		fd[2];
	int		pid1;
	int		pid2;
	int		input;
	int		output;
	char	*path;
	char	**paths;
	char	*cmd1;
	char	*cmd2;
}	t_pipex;

/*	pipex.c	*/

/*	parsing.c	*/
char	**get_paths(char **envp);
void	get_cmd(char *argv, char *cmd, t_pipex *pipex, char **envp);

/*	utils.c	*/
void	ft_perror(char *str);
void	free_split(char **str);

#endif
