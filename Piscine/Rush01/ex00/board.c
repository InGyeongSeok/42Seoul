/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:18:33 by sanseo            #+#    #+#             */
/*   Updated: 2023/01/22 22:39:12 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int **board)
{
	int		i;
	int		j;
	char	ch;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ch = board[i][j] + '0';
			write(1, &ch, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int	check_all(int **ck)
{
	if (ck[0][0] == 4 && ck[0][1] == 3 && ck[0][2] == 2 && ck[0][3] == 1
		&& ck[1][0] == 3 && ck[1][1] == 4 && ck[1][2] == 1 && ck[1][3] == 2
		&& ck[2][0] == 2 && ck[2][1] == 1 && ck[2][2] == 4 && ck[2][3] == 3
		&& ck[3][0] == 1 && ck[3][1] == 2 && ck[3][2] == 3 && ck[3][3] == 4)
		return (0);
	return (1);
}

int	**change(int **ck, int i)
{
	while (ck[i / 4][i % 4] == 4)
		i--;
	ck[i / 4][i % 4]++;
	i++;
	while (i < 16)
	{
		ck[i / 4][i % 4] = 1;
		i++;
	}
	return (ck);
}

int	board_row_check(int **board, int value)
{
	int	i;
	int	j;

	i = 0;
	j = value / 4;
	while (i < value % 4)
	{
		if (board[j][i] == board[j][value % 4])
			return (0);
		i++;
	}
	return (1);
}

int	board_column_check(int **board, int value)
{
	int	i;
	int	j;

	i = 0;
	j = value % 4;
	while (i < value / 4)
	{
		if (board[i][j] == board[value / 4][j])
			return (0);
		i++;
	}
	return (1);
}
