/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:13:27 by inseok            #+#    #+#             */
/*   Updated: 2023/01/24 09:55:12 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	promising(int index, int *queen)
{
	int	k;

	k = 0;
	while (k < index)
	{
		if ((queen[k] == queen[index]) || (queen[index] - queen[k] == index - k)
			|| (queen[index] - queen[k] == k - index))
			return (0);
		k++;
	}
	return (1);
}

void	writequeen(int *queen)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = queen[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	find_queens(int index, int *queen)
{
	int		j;

	if (index == 10)
	{
		queen[10]++;
		writequeen(queen);
	}
	else
	{
		j = 0;
		while (j <= 9)
		{
			queen[index] = j;
			if (promising(index, queen))
				find_queens(index + 1, queen);
			j++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queen[11];
	int	i;

	i = 0;
	while (i < 11)
	{
		queen[i] = 0;
		i++;
	}
	find_queens(0, queen);
	return (queen[10]);
}
