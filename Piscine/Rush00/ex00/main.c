/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:13:42 by seunlee2          #+#    #+#             */
/*   Updated: 2023/01/15 20:12:02 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	atoi(char *str)
{
	long long	num;
	int			i;

	num = 0;
	i = 0;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (!(1 <= num && num <= 2147483647))
			return (-1);
		i++;
	}
	return (num);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;
	int	x_is_num;
	int	y_is_num;

	if (argc == 3)
	{
		x_is_num = str_is_numeric(argv[1]);
		y_is_num = str_is_numeric(argv[2]);
		if (x_is_num == 1 && y_is_num == 1)
		{
			x = atoi(argv[1]);
			y = atoi(argv[2]);
			if (!(x == -1 || y == -1))
				rush(x, y);
		}
	}
	return (0);
}
