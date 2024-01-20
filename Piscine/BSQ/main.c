/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:32:21 by seonglim          #+#    #+#             */
/*   Updated: 2023/02/02 12:24:19 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_map(char **map_arr)
{
	char	*str;

	while (*map_arr)
	{
		str = *map_arr;
		while (*str)
			write(1, str++, 1);
		write(1, "\n", 1);
		++map_arr;
	}
}

int	err_print(char *str)
{
	free(str);
	write(2, "map error\n", 10);
	return (-1);
}

void	change_map(char **map_arr, t_index range, char set)
{
	int	end_i;
	int	end_j;
	int	start_j;

	start_j = range.j;
	end_i = range.i + range.diag;
	end_j = range.j + range.diag;
	while (range.i <= end_i)
	{
		range.j = start_j;
		while (range.j <= end_j)
		{
			map_arr[range.i][range.j] = set;
			++range.j;
		}
		++range.i;
	}
}

int	goinfre(char *map_str, char **map_arr, int flag)
{
	int	i;

	free(map_str);
	if (flag == -1)
		return (-1);
	i = -1;
	while (map_arr[++i])
		free(map_arr[i]);
	free(map_arr);
	if (-2 == flag)
		err_print(NULL);
	return (flag);
}

int	main(int argc, char **argv)
{
	char	*map_str;
	char	**map_arr;
	int		i;
	t_index	result;

	if (argc > 2)
		return (err_print(NULL));
	map_str = make_map_str(argc, argv);
	if (!map_str)
		return (-1);
	if (valid_map(map_str) == -1)
		return (err_print(map_str));
	map_arr = make_map(map_str);
	if (!map_arr)
		return (goinfre(map_str, NULL, -1));
	i = -1;
	while (map_str[++i] != '\n')
		;
	result = check_map_arr(map_arr, map_str[i - 2]);
	if (result.i == -1)
		return (goinfre(map_str, map_arr, -2));
	change_map(map_arr, result, map_str[i - 1]);
	print_map(map_arr);
	return (goinfre(map_str, map_arr, 0));
}
