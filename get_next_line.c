/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:57:47 by inseok            #+#    #+#             */
/*   Updated: 2023/05/27 20:43:38 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd_list	*get_fd_node(int fd, t_fd_list **fd_list)
{
	t_fd_list	*fd_node;

	fd_node = *fd_list;
	while (fd_node != NULL)
	{
		if (fd_node->fd == fd)
			break ;
		fd_node = fd_node->next;
	}
	if (!fd_node)
	{
		fd_node = (t_fd_list *)malloc(sizeof(t_fd_list));
		if (!fd_node)
			return (NULL);
		fd_node->fd = fd;
		fd_node->line = NULL;
		fd_node->next = *fd_list;
		fd_node->prev = NULL;
		if (fd_node->next)
			fd_node->next->prev = fd_node;
		*fd_list = fd_node;
	}
	return (fd_node);
}

void	delete_node(t_fd_list *fd_node, t_fd_list **fd_list)
{
	if (fd_node->prev)
		fd_node->prev->next = fd_node->next;
	else
		*fd_list = fd_node->next;
	if (fd_node->next)
		fd_node->next->prev = fd_node->prev;
	free(fd_node->line);
	free(fd_node);
}

int	read_buffer(t_fd_list *fd_node, t_fd_list **fd_list)
{
	char	*read_buffer;
	int		read_size;
	int		line_index;
	char	*temp;

	line_index = 0;
	read_size = 0;
	read_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!read_buffer)
	{
		delete_node(fd_node, fd_list);
		return (0);
	}
	while (gnl_strchr(fd_node->line + line_index) < 0)
	{
		line_index += read_size;
		read_size = read(fd_node->fd, read_buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		temp = gnl_strjoin(fd_node->line, read_buffer, read_size);
		if (!temp)
		{
			free(read_buffer);
			delete_node(fd_node, fd_list);
			return (0);
		}
		free(fd_node->line);
		fd_node->line = temp;
	}
	free(read_buffer);
	if (read_size < 0)
	{
		delete_node(fd_node, fd_list);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_fd_list	*fd_list;
	t_fd_list			*fd_node;
	char				*result;
	int					new_line_index;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	fd_node = get_fd_node(fd, &fd_list);
	if (!fd_node || !read_buffer(fd_node, &fd_list))
		return (NULL);
	new_line_index = gnl_strchr(fd_node->line);
	if (new_line_index < 0)
	{
		result = gnl_strndup(fd_node->line, gnl_strlen(fd_node->line));
		delete_node(fd_node, &fd_list);
		return (result);
	}
	result = gnl_split(&(fd_node->line), new_line_index);
	if (!result)
	{
		delete_node(fd_node, &fd_list);
		return (NULL);
	}
	return (result);
}
