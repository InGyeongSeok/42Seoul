/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:34:13 by seonglim          #+#    #+#             */
/*   Updated: 2023/02/02 08:38:48 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	first_row_check(char *map)
{
	int	i;
	int	j;

	if (*map < '1' || *map > '9')
		return (-1);
	i = -1;
	while (map[++i] != '\n')
		;
	j = 0;
	while (++j < i - 3)
		if (map[j] < '0' || map[j] > '9')
			return (-1);
	if (map[i - 1] == map[i - 2] || map[i - 1] == map[i - 3]
		|| map[i - 2] == map[i - 3])
		return (-1);
	j = i - 4;
	while (++j < i)
	{
		if (map[j] < 32 || map[j] > 126)
			return (-1);
	}
	return (1);
}

int	row_check(char *map)
{
	int	count;
	int	i;

	i = -1;
	while (map[++i] != '\n')
		;
	count = 0;
	while (map[++i] != '\n' && map[i])
		++count;
	if (!count)
		return (-1);
	i = -1;
	while (map[++i] != '\n')
		;
	return (is_valid_row(map, count, i, i));
}

int	is_collide_check(char **map_arr, char charset, t_index index)
{
	int	end_i;
	int	end_j;

	end_i = index.i + index.diag + 1;
	end_j = index.j + index.diag + 1;
	if (map_arr[index.i][index.j] == charset)
		return (0);
	while (index.i <= end_i)
	{
		if (map_arr[index.i][end_j] == charset)
			return (0);
		if (map_arr[end_i][index.j] == charset)
			return (0);
		++index.i;
		++index.j;
	}
	return (1);
}

int	is_valid_row(char *map, int count, int i, int k)
{
	int	tmpcount;
	int	row_num;

	tmpcount = -1;
	row_num = 1;
	while (map[++i] && ++tmpcount >= 0)
	{
		if (map[i] != map[k - 1] && map[i] != map[k - 2] && map[i] != map[k - 3]
			&& map[i] != '\n')
			return (-1);
		if (map[i] == '\n')
		{
			if (count != tmpcount)
				return (-1);
			tmpcount = -1;
			if (++row_num > bbq_atoi(map))
			{
				if (map[i + 1] == '\0')
					return (1);
				else
					return (-1);
			}
		}
	}
	return (-1);
}

t_index	check_map_arr(char **map_arr, char charset)
{
	t_index	max_index;
	t_index	now_index;
	int		row_size;
	int		col_size;
	int		flag;

	row_size = -1;
	while (map_arr[++row_size])
		;
	col_size = -1;
	while (map_arr[0][++col_size])
		;
	max_index = first_valid_start(map_arr, row_size, col_size, charset);
	if (max_index.i == -1)
		return (max_index);
	flag = 0;
	now_index = max_index;
	while (now_index.i < row_size)
	{
		if (flag++)
			now_index.j = 0;
		search_max_index(map_arr, charset, &now_index, &max_index);
		++now_index.i;
	}
	return (max_index);
}
