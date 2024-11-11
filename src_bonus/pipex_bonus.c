/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:12:17 by abelmoha          #+#    #+#             */
/*   Updated: 2024/07/11 19:39:19 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../libft/get_next_line/get_next_line.h"

void	put_hd_in_pipe(char *limiter, int *fd_pipe)
{
	char	*line;

	close(fd_pipe[0]);
	while (1)
	{
		line = get_next_line(0);
		if ((ft_strncmp(line, limiter, ft_strlen(limiter)) == 0) && \
			(ft_strlen(line) - 1 == ft_strlen(limiter)))
		{
			free(line);
			get_next_line(-5);
			exit_gestion(0);
		}
		ft_putstr_fd(line, fd_pipe[1]);
		free(line);
	}
}

void	here_doc(char *limiter)
{
	pid_t	pid;
	int		fd_pipe[2];

	if (pipe(fd_pipe) == -1)
		exit_gestion(0);
	pid = fork();
	if (!pid)
		put_hd_in_pipe(limiter, fd_pipe);
	else
	{
		close(fd_pipe[1]);
		dup2(fd_pipe[0], 0);
	}
}

void	do_pipe(char *cmd, char **env)
{
	int	fd_pipe[2];
	int	pid;

	if (pipe(fd_pipe) == -1)
		exit_gestion(0);
	pid = fork();
	if (pid == 0)
	{
		close(fd_pipe[0]);
		dup2(fd_pipe[1], 1);
		exec(cmd, env);
	}
	else
	{
		close(fd_pipe[1]);
		dup2(fd_pipe[0], 0);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	fd_in;
	int	fd_out;
	int	i;

	if (argc < 5)
		exit_gestion(1);
	if (strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
			exit_gestion(1);
		i = 3;
		fd_out = open_file(argv[argc - 1], 2);
		here_doc(argv[2]);
	}
	else
	{
		i = 2;
		fd_in = open_file(argv[1], 0);
		fd_out = open_file(argv[argc - 1], 1);
		dup2(fd_in, 0);
	}
	while (i < argc - 2)
		do_pipe(argv[i++], env);
	dup2(fd_out, 1);
	exec(argv[argc - 2], env);
}
