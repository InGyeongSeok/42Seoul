/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 08:59:52 by inseok            #+#    #+#             */
/*   Updated: 2023/03/29 23:18:52 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char *str, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	if (str[0] != c)
		flag = 1;
	else
		flag = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
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

static char	*ft_split_strdup(const char *s, char c)
{
	size_t	i;
	size_t	count;
	char	*str;

	count = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < count)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static void	ft_free(char **list)
{
	size_t	j;

	j = 0;
	while (list[j])
	{
		free(list[j]);
		j++;
	}
	free(list);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		index;
	char	**result;

	result = (char **)malloc(sizeof(char *) * (word_count((char *)s, c) + 1));
	if (!result)
		return (0);
	i = 0;
	index = 0;
	while (index < word_count((char *)s, c))
	{
		while (s[i] == c && s[i])
			i++;
		result[index] = ft_split_strdup(&s[i], c);
		if (!result[index])
		{
			ft_free(result);
			return (NULL);
		}
		i += ft_strlen((const char *)(result[index]));
		index++;
	}
	result[index] = 0;
	return (result);
}
