/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:58:43 by inseok            #+#    #+#             */
/*   Updated: 2023/05/27 21:09:38 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_fd_list
{
	int					fd;
	char				*line;
	struct s_fd_list	*next;
	struct s_fd_list	*prev;
}						t_fd_list;

char					*get_next_line(int fd);
t_fd_list				*get_fd_node(int fd, t_fd_list **fd_list);
void					delete_node(t_fd_list *fd_node, t_fd_list **fd_list);
int						read_buffer(t_fd_list *fd_node, t_fd_list **fd_list);

char					*gnl_split(char **line, int i);
int						gnl_strlen(const char *s);
char					*gnl_strjoin(char const *s1, char const *s2,
							int s2_len);
int						gnl_strchr(const char *s);
char					*gnl_strndup(const char *s, int n);
#endif