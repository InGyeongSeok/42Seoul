/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:58:43 by inseok            #+#    #+#             */
/*   Updated: 2023/05/22 21:33:31 by inseok           ###   ########.fr       */
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

char *gnl_split(char **line, int i);
char * final_line(char **line, int read_size);
char * get_next_line(int fd);

int gnl_strlen(const char *s);
char *gnl_strjoin(char const *s1, char const *s2, int s2_len);
int gnl_strchr(const char *s);
char *gnl_strndup(const char *s, int n);
#endif