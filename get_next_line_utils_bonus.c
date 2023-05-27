/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:58:21 by inseok            #+#    #+#             */
/*   Updated: 2023/05/27 21:09:36 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_strchr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-2);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strjoin(char const *s1, char const *s2, int s2_len)
{
	size_t	len;
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (gnl_strndup(s2, s2_len));
	else if (!s2)
		return (gnl_strndup(s1, gnl_strlen(s1)));
	len = gnl_strlen((char *)s1) + s2_len;
	s3 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s3)
		return (NULL);
	while (*s1)
		s3[i++] = *s1++;
	while (j < s2_len)
		s3[i + j++] = *s2++;
	s3[i + j] = '\0';
	return (s3);
}

int	gnl_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strndup(const char *s, int n)
{
	char	*result;
	int		i;

	if (!s)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*gnl_split(char **line, int i)
{
	char	*result;
	char	*save;
	int		line_len;

	line_len = gnl_strlen(*line);
	result = gnl_strndup(*line, i + 1);
	if (!result)
		return (NULL);
	if (line_len - 1 != i)
	{
		save = gnl_strndup(*line + i + 1, line_len - i - 1);
		if (!save)
		{
			free(result);
			return (NULL);
		}
	}
	else
		save = NULL;
	free(*line);
	*line = save;
	return (result);
}
