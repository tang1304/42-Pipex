/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:50:32 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/07 15:32:26 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**get_paths(char **envp)
{
	char	*envp_path;
	char	**paths;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			envp_path = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
			if (envp_path != NULL)
				break ;
		}
	}
	paths = ft_split(envp_path + 5, ':');
	if (paths == NULL)
		ft_perror("Malloc error");
	return (paths);
}

static void	open_files(t_pipex *pipex, int ac, char **av)
{
	if (pipex->here_doc == 1)
	{
		pipex->input = open(x, O_RDONLY);
		if (pipex->input == -1)
			perror(x);
		pipex->output = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (pipex->output == -1)
			perror(av[ac - 1]);
		pipex->cmd = 3;
	}
	else
	{
		pipex->input = open(av[1], O_RDONLY);
		if (pipex->input == -1)
			perror(av[1]);
		pipex->output = open(av [ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (pipex->output == -1)
			perror(av[ac - 1]);
		pipex->cmd = 2;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		ft_error(ARGS_ERROR);
	data_init(&pipex, argc, argv);
	open_files(&pipex, argc, argv);
	pipex.paths = get_paths(envp);
	if (dup2(pipex.input, STDIN_FILENO) == -1)
	{
		free_split(pipex.paths);
		ft_perror("Dup error");
	}
	while (pipex.cmd < argc - 2)
		command_init(argv[pipex.cmd++], envp, &pipex);
	if ()
	close_parents(&pipex);
	free_split(pipex.paths);
}
