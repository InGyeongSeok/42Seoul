/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:35:55 by seonglim          #+#    #+#             */
/*   Updated: 2023/02/02 07:22:29 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*read_map(char *filename)
{
	char	*str;
	int		fd;
	char	c;
	int		count;

	fd = open(filename, O_RDONLY);
	count = 0;
	if (fd < 0)
		return (NULL);
	while (read(fd, &c, 1) > 0)
		++count;
	close(fd);
	str = (char *)malloc(count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	count = 0;
	while (read(fd, &c, 1) > 0)
		str[count++] = c;
	return (str);
}

int	valid_map(char *map_str)
{
	if (first_row_check(map_str) == -1)
		return (-1);
	if (row_check(map_str) == -1)
		return (-1);
	return (1);
}

void	alloc_map_strs(char *map, char **map_arr, int num)
{
	int	i;
	int	count;

	i = -1;
	while (map[++i] != '\n')
		;
	count = 0;
	while (map[++i] != '\n')
		++count;
	i = -1;
	while (++i < num)
	{
		map_arr[i] = (char *)malloc(count + 1);
		map_arr[i][count] = '\0';
	}
}

char	**make_map(char *map)
{
	char	**map_arr;
	int		num;
	int		i;
	int		j;
	int		count;

	num = bbq_atoi(map);
	map_arr = (char **)malloc(sizeof(char *) * (num + 1));
	if (!map_arr)
		return (NULL);
	map_arr[num] = NULL;
	alloc_map_strs(map, map_arr, num);
	j = -1;
	while (map[++j] != '\n')
		;
	i = -1;
	while (++i < num)
	{
		count = 0;
		while (map[++j] != '\n')
			map_arr[i][count++] = map[j];
	}
	return (map_arr);
}

char	*make_map_str(int argc, char **argv)
{
	int		i;
	char	*str;
	char	buf[100001];

	if (argc == 1)
	{
		str = (char *)malloc(1);
		*str = '\0';
		i = 1;
		while (1)
		{
			i = read(0, buf, 100000);
			if (i <= 0)
				break ;
			buf[i] = '\0';
			str_cat_alloc(&str, buf, i);
		}
		return (str);
	}
	else
		return (read_map(argv[1]));
	return (NULL);
}
