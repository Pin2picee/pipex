/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:35:16 by abelmoha          #+#    #+#             */
/*   Updated: 2024/05/09 17:05:32 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// le but est de 

void	execute(char *cmd, char **env)
{
	char	*chemin;
	char	**s_cmd;

	s_cmd = ft_split(cmd, ' ');
	chemin = find_path(s_cmd[0], env);
	if (chemin != NULL)
		execve(chemin, s_cmd, env);
	free_tab(s_cmd);
	free(chemin);
}

void	father(int *pipe_fd, char **argv, char **env)
{
	int	fd;

	fd = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd == -1)
		exit(EXIT_FAILURE);
	dup2(fd, 1);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	execute(argv[3], env);
}

void	child(int *pipe_fd, char **argv, char **env)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	dup2(fd, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	execute(argv[2], env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
		exit(EXIT_FAILURE);
	if (pipe(pipe_fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == 0)
		child(pipe_fd, argv, env);
	else
		father(pipe_fd, argv, env);
}
