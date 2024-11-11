/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:21:27 by abelmoha          #+#    #+#             */
/*   Updated: 2024/05/15 23:37:58 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*find_path(char *cmd, char **env);
void	free_tab(char **tab);
void	exit_gestion(int option);
int		open_file(char *file, int option);

#endif
