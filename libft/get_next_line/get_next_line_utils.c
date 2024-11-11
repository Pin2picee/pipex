/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:29:59 by abelmoha          #+#    #+#             */
/*   Updated: 2024/05/15 23:36:39 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	found_newline(t_gnl_list *stash)
{
	int			i;
	t_gnl_list	*current;

	if (stash == NULL)
		return (0);
	current = last_maillon(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_gnl_list	*last_maillon(t_gnl_list *stash)
{
	t_gnl_list	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

// generate_line compte les caracteres stocke dans
// chaque maillon puis les additione pour malloc la ligne a envoyez
// genere et malloc la ligne en parcourant chaque
// copy de mon buff sur chaque maillon
void	generate_line(char **line, t_gnl_list *stash)
{
	int	i_maillon;
	int	len;

	len = 0;
	while (stash)
	{
		i_maillon = 0;
		while (stash->content[i_maillon])
		{
			if (stash->content[i_maillon] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i_maillon++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

size_t	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while (*(str++))
	{
		i++;
	}
	return (i);
}

void	free_stash(t_gnl_list *stash)
{
	t_gnl_list	*current;
	t_gnl_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
