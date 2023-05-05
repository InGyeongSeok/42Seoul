/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:46:50 by inseok            #+#    #+#             */
/*   Updated: 2023/05/04 09:46:50 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len;
	char	*result;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (gnl_strdup(s2));
	else if (!s2)
		return (gnl_strdup(s1));
	len = gnl_strlen((char *)s1) + gnl_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}


char	*line_clear(char **line)
{
	free(*line);
	*line = NULL;
	return (NULL);
}

char	*gnl_strndup(const char *src, int len)
{
	char	*dest;
	int		i;

	if (!src)
		return (0);
	dest = (char *)malloc(sizeof(char) * (len + 2)); // ê°œí–‰ + NULL
	if (!dest)
		return (0);
	i = 0;
	while (i <= len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*read_buf(int fd, char *line)
{
	int		readsize;
	char	*buffer;
	//char	*tmp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer) //
		return (line_clear(&line)); //line?— ?žˆ?˜ ê²? ?—†?• ê³? line?„ NULLë¡? ë§Œë“¤ê¸?
	readsize = 1;
	buffer[0] = '\0';
	//printf("newline/index %d\n", find_newline(buffer));

	while (readsize > 0 && find_newline(buffer) < 0)
	{
		readsize = read (fd, buffer, BUFFER_SIZE);
		//printf("readsize: %d\n", readsize);

		if (readsize > 0)
		{
			buffer[readsize] = '\0';
			line = gnl_strjoin(line, buffer);
			// if (!tmp)
			// {
			// 	free(buffer);
			// 	return (line_clear(&line));
			// }
			// line = tmp;
		}
	}
	free(buffer);
	//printf("line: %s\n", line);
	if (readsize == -1) // read ?ï¿½ï¿½ë¥˜ëŠ” ì´ˆê¸°?ï¿½ï¿½
		return (line_clear(&line));
	return (line);
}

int	find_newline(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*make_line(char * line, int index)
{
	char	*result;
	if(index < 0)
		index = gnl_strlen(line);
	//printf("strlen: %d\n", index);
	result = gnl_strndup(line, index);
	//printf("makeline/result %s\n", result);
	if(!result)
		return (NULL);
	char *tmp = gnl_strdup(line + index + 1);
    line_clear(&line);
    line = tmp;
	return (result);
}

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strdup(const char *src)
{
	char	*dest;
	size_t	len;
	size_t	i;

	len = gnl_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i<= len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char	*next_line(char *line, int index)
{
	char	*save;

	if (index < 0)
	{
		save = NULL;
		//printf("save: %s", save);
		//line_clear(&line);
		return (save);
	}
	// if (!line[index+1])
	// 	return (line_clear(&line));
	save = gnl_strdup(line + index + 1);
	//printf("next_line: %s", save);
	line_clear(&line);
	if (!save)
		return (NULL);
	return (save);
}

void	check_leak(void)
{
	system("leaks --list -- a.out");
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*result;
	int			index;

	if (fd < 0)
		return (NULL);
	line = read_buf (fd, line);
	//printf("main/line: %s", line);

	if (!line) // read_bufï¿??? ?ï¿½ï¿½ë¥˜ë©´ NULL ë°˜í™˜
		return (NULL);
	index = find_newline(line);
	//printf("main/index: %d\n", index);
	result = make_line(line, index);
	//printf("main/result: %s", result);
	if (!result)
		return (line_clear(&line));
	//printf("main/line2: %s", line);
	line = next_line(line, index);
	//printf("main/line3: %s", line);

	//atexit(check_leak);

	return (result);
}
