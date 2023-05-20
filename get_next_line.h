/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:45:04 by inseok            #+#    #+#             */
/*   Updated: 2023/05/20 20:24:01 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>



//////////////
#include <stdio.h>
////////////////////

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

char *add_line(char** line, char* read_buffer);
char *gnl_split(char **line, int i);
char * final_line(char **line, int read_size);
char * get_next_line(int fd);

int gnl_strlen(const char *s);
char	*gnl_strjoin(char const *s1, char const *s2);
int gnl_strchr(const char *s);
char *gnl_strndup(const char *s, int n);
void	*gnl_memset(void *b, int c, size_t len);
#endif
