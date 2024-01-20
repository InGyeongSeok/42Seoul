/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwoc <seongwoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:40:30 by seongwoc          #+#    #+#             */
/*   Updated: 2023/01/29 22:42:56 by seongwoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);

int	is_read(void)
{
	int		fd;
	char	buf[1];
	int		num;
	int		check;

	num = 0;
	check = 0;
	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
	{
		write(1, "Dict Error\n", 5);
		return (-1);
	}
	while (1)
	{
		check = read(fd, buf, 1);
		if (check <= 0)
			break ;
		num += check;
	}
	close(fd);
	return (num);
}

char	**read_dict(char *dict_name)
{
	char	**dict_arr;
	char	*buf;
	int		fd;

	if (is_read() == -1)
		return (0);
	buf = (char *)malloc(sizeof(char) * (is_read() + 1));
	fd = open(dict_name, O_RDONLY);
	read(fd, buf, is_read());
	buf[is_read()] = '\0';
	close(fd);
	dict_arr = ft_split(buf, "\n");
	free(buf);
	return (dict_arr);
}
