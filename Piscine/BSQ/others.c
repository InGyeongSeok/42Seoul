/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:37:07 by seonglim          #+#    #+#             */
/*   Updated: 2023/02/02 08:40:13 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	str_cat_alloc(char **dest, char *src, int j)
{
	int		i;
	int		tmp;
	char	*org_dest;

	org_dest = *dest;
	i = -1;
	while (org_dest[++i])
		;
	*dest = (char *)malloc(i + j + 1);
	tmp = -1;
	while (++tmp < i)
		(*dest)[tmp] = org_dest[tmp];
	tmp = -1;
	while (++tmp < j)
		(*dest)[tmp + i] = src[tmp];
	(*dest)[tmp + i] = src[tmp];
	free(org_dest);
}

t_index	first_valid_start(char **map_arr, int row_size, int col_size, char set)
{
	t_index	start;

	start.diag = 0;
	start.i = -1;
	while (++start.i < row_size)
	{
		start.j = -1;
		while (++start.j < col_size)
		{
			if (map_arr[start.i][start.j] != set)
				return (start);
		}
	}
	start.i = -1;
	start.j = -1;
	return (start);
}

int	bbq_atoi(char *str)
{
	int	i;
	int	num;
	int	len;

	len = 0;
	i = -1;
	while (str[++i] != '\n')
		;
	len = i - 3;
	num = 0;
	i = -1;
	while (++i < len)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}

void	search_max_index(char **map_arr, char charset,
			t_index *now_index, t_index *max_index)
{
	int		row_size;
	int		col_size;

	row_size = -1;
	while (map_arr[++row_size])
		;
	col_size = -1;
	while (map_arr[0][++col_size])
		;
	while (now_index->j < col_size)
	{
		while (now_index->i + now_index->diag + 1 < row_size && now_index->j
			+ now_index->diag + 1 < col_size)
		{
			if (is_collide_check(map_arr, charset, *now_index))
				++now_index->diag;
			else
				break ;
		}
		if (now_index->diag > max_index->diag)
			*max_index = *now_index;
		now_index->diag = 0;
		++now_index->j;
	}
}
