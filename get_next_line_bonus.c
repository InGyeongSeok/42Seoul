/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:49:51 by inseok            #+#    #+#             */
/*   Updated: 2023/05/27 16:16:15 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*gnl_lstnew(int fd, t_list **head)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->index = fd;
	new->next = *head;
	return (new);
}

t_list	*find_node(int fd, t_list *head)
{
	t_list	*p;

	p = head;
	while (p != NULL)
	{
		if (p->index == fd)
			return (p);
		p = head->next;
	}
	return (NULL);
}

void	free_list(int fd, t_list **head)
{
	t_list	*p;
	t_list	*temp;

	p = *head;
	temp = find_node(fd, *head);
	if (temp == *head)
	{
		*head = (*head)->next;
		free(temp);
	}
	else
	{
		while (p != NULL)
		{
			if (p == temp)
			{
				p->next = p->next->next;
				free(temp);
			}
			p = p->next;
		}
	}
}

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
	static t_list	*head;
	t_list			*p;
	char			*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!(find_node(fd, head)))
		if (!(gnl_lstnew(fd, &head)))
			return (NULL);
	p = find_node(fd, head);
	p->line = read_buffer(&(p->line), fd);
	if (gnl_strchr(p->line) < 0)
	{
		result = p->line;
		p->line = NULL;
		return (result);
	}
	result = gnl_split(&(p->line), gnl_strchr(p->line));
	if (!result)
		return (free_line(&(p->line)));
	return (result);
}
