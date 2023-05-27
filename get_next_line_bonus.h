/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:48:39 by inseok            #+#    #+#             */
/*   Updated: 2023/05/23 15:48:39 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	int index;
	char *line;
	struct s_list *next;
} t_list;

char * get_next_line(int fd);
char* free_line(char ** line);
char *read_buffer(char **line, int fd);
t_list	*gnl_lstnew(int fd, t_list **head);
t_list *find_node(int fd, t_list * head);

char *gnl_split(char **line, int i);
int gnl_strlen(const char *s);
char *gnl_strjoin(char const *s1, char const *s2, int s2_len);
int gnl_strchr(const char *s);
char *gnl_strndup(const char *s, int n);
#endif