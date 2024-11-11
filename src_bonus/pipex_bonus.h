/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:42:02 by abelmoha          #+#    #+#             */
/*   Updated: 2024/05/15 23:54:16 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include<sys/types.h>
# include<sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

void	exit_gestion(int option);
void	free_tabs(char**tabs);
void	exec(char *cmd, char **env);
int		open_file(char *file, int option);
char	*find_path(char **s_cmd, char **env);

#endif