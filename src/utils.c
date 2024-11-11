/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:50:00 by abelmoha          #+#    #+#             */
/*   Updated: 2024/05/09 17:14:08 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **env)
{
	int		i;
	char	**path;
	char	*chemin;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	path = ft_split(env[i] + 5, ':');
	i = -1;
	while (path[++i])
	{
		chemin = ft_strjoin(path[i], "/");
		chemin = ft_strjoin(chemin, cmd);
		if (access(chemin, F_OK | X_OK) == 0)
			return (chemin);
	}
	free_tab(path);
	free(chemin);
	return (NULL);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
