/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:55:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/22 16:53:31 by tgellon          ###   ########lyon.fr   */
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

# define ARGS_ERROR	"Wrong args input\nMust be : ./pipex file1 cmd1 cmd2 file2"

typedef struct s_pipex
{
	int		pipe[2];
	int		pid1;
	int		pid2;
	int		input;
	int		output;
	char	*path;
	char	**paths;
	char	**cmd1;
	char	**cmd2;
}	t_pipex;

/*	cmd_parsing.c	*/
void	get_cmd(char *argv, t_pipex *pipex, char **cmd_args, char **envp);

/*	utils.c	*/
void	data_init(t_pipex *pipex);
void	free_split(char **str);
void	free_split_from_i(char **str, int i);
void	free_all(t_pipex *pipex, char **cmd_args, char *cmd, int i);

/*	utils_2.c	*/

void	in_out_close(t_pipex *pipex);
void	close_fds(t_pipex *pipex);
void	close_all(t_pipex *pipex);

/*	errors.c	*/
void	ft_perror(char *str);
void	dup2_error(t_pipex *pipex);
void	get_cmd_error(char *cmd);
void	execve_error(t_pipex *pipex, char **cmd_args);
void	directory_error(char *str);

#endif
