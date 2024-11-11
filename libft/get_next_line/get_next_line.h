/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:50:00 by abelmoha          #+#    #+#             */
/*   Updated: 2024/05/15 23:36:19 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h> // enlever

//     Mon buffer temp
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// ma structure que je vais chainer pour chaque liste

typedef struct s_gnl_list
{
	char				*content;
	struct s_gnl_list	*next;
}				t_gnl_list;

// utils

void		extract_line(t_gnl_list *stash, char **line);
void		generate_line(char **line, t_gnl_list *stash);
t_gnl_list	*last_maillon(t_gnl_list *stash);
int			found_newline(t_gnl_list *stash);
size_t		ft_strlen_gnl(const char *str);
void		free_stash(t_gnl_list *stash);

// principal
char		*get_next_line(int fd);
void		buff_to_stash(t_gnl_list **stash, char *buff, int lettre_lu);
void		read_and_stash(t_gnl_list **stash, int fd);

void		clean_stash(t_gnl_list **stash);
char		*get_next_line(int fd);

#endif