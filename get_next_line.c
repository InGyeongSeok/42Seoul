/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:57:47 by inseok            #+#    #+#             */
/*   Updated: 2023/05/22 22:19:10 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*read_buffer;
	int			read_size;
	static char	*line;
	char		*temp;
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	read_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!read_buffer)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	while (gnl_strchr(line) < 0)
	{
		read_size = read(fd, read_buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		temp = gnl_strjoin(line, read_buffer, read_size);
		free(line);
		line = temp;
	}
	free(read_buffer);
	if(read_size < 0)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	if(gnl_strchr(line) < 0)
	{
		result = line;
		line = NULL;
		return (result);
	}
	result = gnl_split(&line, gnl_strchr(line));
	if (!result)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	return (result);
}
