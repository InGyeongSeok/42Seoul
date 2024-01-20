/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunlee <gunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:33:40 by gunlee            #+#    #+#             */
/*   Updated: 2023/01/29 19:33:41 by gunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	word_count(char *str, int length)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	if (str[0] != '\0')
		flag = 1;
	else
		flag = 0;
	count = 0;
	while (i < length)
	{
		if (str[i] == '\0')
			flag = 1;
		else
		{
			if (flag == 1)
				count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

char	*init_str(char *str, char *charset, int length)
{
	int		i;
	int		j;
	char	*new_str;

	new_str = ft_strdup(str);
	i = 0;
	while (i < ft_strlen(charset))
	{
		j = 0;
		while (j < length)
		{
			if (new_str[j] == charset[i])
				new_str[j] = '\0';
			j++;
		}
		i++;
	}
	return (new_str);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		index;
	int		len;
	char	*removed;
	char	**result;

	len = ft_strlen(str);
	removed = init_str(str, charset, len);
	result = (char **)malloc(sizeof(char *) * (word_count(removed, len) + 1));
	if (result == NULL)
		return (0);
	i = 0;
	index = 0;
	while (i < len)
	{
		if (removed[i] == '\0' || !ft_strlen(removed + i))
		{
			i++;
			continue ;
		}
		result[index++] = ft_strdup(removed + i);
		i += ft_strlen(removed + i);
	}
	result[index] = NULL;
	return (result);
}
