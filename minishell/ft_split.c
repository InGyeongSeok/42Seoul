/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:26:20 by seonglim          #+#    #+#             */
/*   Updated: 2023/10/28 02:42:43 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;
	int	is_bef_n_word;

	i = -1;
	count = 0;
	is_bef_n_word = 1;
	while (s[++i])
	{
		if (s[i] != c)
		{
			if (is_bef_n_word)
				++count;
			is_bef_n_word = 0;
		}
		else
			is_bef_n_word = 1;
	}
	return (count);
}

static void	reset_double_arr(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		arr[i] = 0;
		++i;
	}
}

void	free_split(char **arr)
{
	char	**temp;

	if (!arr)
		return ;
	temp = arr;
	while (*temp)
		free(*temp++);
	free(arr);
}

static int	split_str(char **ptr, int *ptr_idx, char const **s, char c)
{
	char	*sub_ptr;
	int		i;

	i = 0;
	while ((*s)[i] != c && (*s)[i])
		++i;
	sub_ptr = malloc(sizeof(char) * (i + 1));
	if (sub_ptr)
	{
		ft_strlcpy(sub_ptr, *s, i + 1);
		ptr[++*ptr_idx] = sub_ptr;
	}
	else
	{
		free_split(ptr);
		return (0);
	}
	*s += i;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		word_count;
	int		ptr_idx;

	if (!s)
		return (NULL);
	word_count = count_word(s, c);
	ptr = malloc(sizeof(char *) * (word_count + 1));
	if (ptr)
	{
		ptr_idx = -1;
		reset_double_arr(ptr, word_count + 1);
		while (*s)
		{
			if (*s == c)
				++s;
			else if (!split_str(ptr, &ptr_idx, &s, c))
				return (0);
		}
	}
	return (ptr);
}
