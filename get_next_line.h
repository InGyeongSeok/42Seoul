/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:46:53 by inseok            #+#    #+#             */
/*   Updated: 2023/05/04 09:46:53 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<limits.h>

char	*gnl_strjoin(const char *s1, const char *s2);
char	*line_clear(char **line);
char	*gnl_strndup(const char *src, int len);
char	*read_buf(int fd, char *line);
int		find_newline(char *s);
char	*make_line(char *line, int index);
char	*gnl_strdup(const char *src);
char	*next_line(char *line, int index);
char	*get_next_line(int fd);
size_t	gnl_strlen(const char *str);
void	check_leak(void);
#endif
