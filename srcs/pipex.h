/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:55:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/28 11:20:05 by tgellon          ###   ########lyon.fr   */
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
	int		file1_status;
	int		file2_status;
	int		input;
	int		output;
	char	*path;
	char	**paths;
	char	**cmd1;
	char	**cmd2;
}	t_pipex;

/*	pipex.c	*/
void	close_parents(t_pipex *pipex);

/*	parsing.c	*/
char	**get_paths(char **envp);
void	get_cmd(char *argv, t_pipex *pipex, char **cmd_args, char **envp);

/*	utils.c	*/
void	free_split(char **str);
void	free_split_from_i(char **str, int i);

/*	errors.c	*/
void	ft_error(char *str);
void	ft_perror(char *str);
void	get_cmd_error(t_pipex *pipex, char **cmd_args, char *path, int i);

#endif
