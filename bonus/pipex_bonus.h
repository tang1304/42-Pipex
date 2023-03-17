/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:49:00 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/17 10:40:47 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include "../libft/libft.h"

# define ARGS_ERROR	"Wrong args input\nMust be : ./pipex_bonus file1 \
cmd_x_times file2\n"
# define HERE_DOC_ARGS_ERROR "Wrongs args input\n Must be : ./pipex_bonus \
here_doc LIMITER cmd1 cmd2 (cmd_x_times) file\n"

typedef struct s_pipex
{
	int		pipes[2];
	int		*children;
	int		pipe_nbr;
	int		cmd_nbr;
	int		cmd;
	int		input;
	int		output;
	int		here_doc;
	char	*path;
	char	**paths;
}	t_pipex;

/*	cmd_parsing_bonus.c	*/
void	get_cmd(char *argv, t_pipex *pipex, char **envp);

/*	cmd_selection_bonus.c	*/
void	pipex_init(char **argv, char **envp, t_pipex *pipex);

/*	here_doc_bonus.c	*/
void	here_doc_init(t_pipex *pipex, int argc);

/*	errors_bonus.c	*/
void	ft_error(char *str);
void	ft_perror(char *str);
void	get_cmd_error(char *cmd);
void	execve_error(t_pipex *pipex, char **cmd_args);
void	directory_error(char *str);

/*	utils_bonus.c	*/
void	data_init(t_pipex *pipex, int argc, char **argv);
void	free_split(char **str);
void	free_split_from_i(char **str, int i);
void	free_all(t_pipex *pipex, char **cmd_args, char *cmd, int i);
void	close_parents(t_pipex *pipex);
void	close_all(t_pipex *pipex);

#endif
