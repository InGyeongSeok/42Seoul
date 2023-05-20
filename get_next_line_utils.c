/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:44:55 by inseok            #+#    #+#             */
/*   Updated: 2023/05/20 20:19:15 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int gnl_strchr(const char *s)
{
	int i;

	i = 0;
	if(!s)
		return(-1);
	while(s[i])
	{
		if (s[i]== '\n')
			return (i);
			i++;
	}
	return (-1);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s3;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (gnl_strndup(s2, gnl_strlen(s2)));
	else if (!s2)
		return (gnl_strndup(s1, gnl_strlen(s1)));
	len = gnl_strlen((char *)s1) + gnl_strlen((char *)s2);
	s3 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s3)
		return (0);
	while (*s1)
		s3[i++] = *s1++;
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}

int gnl_strlen(const char *s)
{
	int	i;

	if(!s)
		return (0);
	i = 0;
	while(s[i])
		i++;
	return(i);
}


char *gnl_strndup(const char *s, int n)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (n + 1));
	if (!result)
		return (0);
	i = 0;
	while (s[i] && i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	*gnl_memset(void *b, int c, size_t len)
{
	size_t			i;

	i = 0;
	if(!b)
		return(0);
	while (len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		len--;
		i++;
	}
	return (b);
}
