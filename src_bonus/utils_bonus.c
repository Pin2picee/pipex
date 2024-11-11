/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:16:50 by abelmoha          #+#    #+#             */
/*   Updated: 2024/07/11 18:38:28 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_gestion(int option)
{
	if (option == 1)
		ft_putstr_fd("It should look like this : \n./a.out (file or here_doc) \
		(if you have here_doc : LIMITER ) cmd cmd2 cmd3 ... file2", 1);
	exit(1);
}

int	open_file(char *file, int option)
{
	int	fd;

	if (option == 0)
		fd = open(file, O_RDONLY);
	if (option == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (option == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	free_tabs(char **tabs)
{
	int	i;

	i = -1;
	while (tabs[++i])
		free(tabs[i]);
	free(tabs);
}

void	exec(char *cmd, char **env)
{
	char	*chemin;
	char	**s_cmd;

	s_cmd = ft_split(cmd, ' ');
	chemin = find_path(s_cmd, env);
	if (chemin != NULL)
		execve(chemin, s_cmd, env);
	free_tabs(s_cmd);
	free(chemin);
}

char	*find_path(char **s_cmd, char **env)
{
	int		i;
	char	**chemins;
	char	*test;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	chemins = ft_split(env[i] + 5, ':');
	i = 0;
	while (chemins[i])
	{
		test = ft_strjoin(chemins[i], "/");
		test = ft_strjoin(test, s_cmd[0]);
		if (access(test, F_OK | X_OK) == 0)
			return (test);
		i++;
	}
	free(test);
	free_tabs(chemins);
	return (NULL);
}
