/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:57:47 by inseok            #+#    #+#             */
/*   Updated: 2023/05/27 14:27:08 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_line(char **line)
{
	free(*line);
	*line = NULL;
	return (NULL);
}

char	*read_buffer(char **line, int fd)
{
	char	*read_buffer;
	int		read_size;
	char	*temp;

	read_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!read_buffer)
		return (free_line(line));
	while (gnl_strchr(*line) < 0)
	{
		read_size = read(fd, read_buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		temp = gnl_strjoin(*line, read_buffer, read_size);
		free(*line);
		*line = temp;
	}
	free(read_buffer);
	if (read_size < 0)
		return (free_line(line));
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = read_buffer(&line, fd);
	if (gnl_strchr(line) < 0)
	{
		result = line;
		line = NULL;
		return (result);
	}
	result = gnl_split(&line, gnl_strchr(line));
	if (!result)
		return (free_line(&line));
	return (result);
}
