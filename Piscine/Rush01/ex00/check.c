/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:16:19 by sanseo            #+#    #+#             */
/*   Updated: 2023/01/22 14:16:21 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	board_row_check(int **board, int value);
int	board_column_check(int **board, int value);

int	chk_row_top(int **arr, int sight, int row)
{
	int	k;
	int	max;

	max = 0;
	k = 0;
	while (k < 4)
	{
		if (arr[k][row] > max)
		{
			max = arr[k][row];
			sight--;
		}
		k++;
	}
	if (sight != 0)
		return (0);
	return (1);
}

int	chk_row_bot(int **arr, int sight, int row)
{
	int	k;
	int	max;

	max = 0;
	k = 3;
	while (k >= 0)
	{
		if (arr[k][row] > max)
		{
			max = arr[k][row];
			sight--;
		}
		k--;
	}
	if (sight != 0)
		return (0);
	return (1);
}

int	chk_col_left(int **arr, int sight, int col)
{
	int	k;
	int	max;

	max = 0;
	k = 0;
	while (k < 4)
	{
		if (arr[col][k] > max)
		{
			max = arr[col][k];
			sight--;
		}
		k++;
	}
	if (sight != 0)
		return (0);
	return (1);
}

int	chk_col_right(int **arr, int sight, int col)
{
	int	k;
	int	max;

	max = 0;
	k = 3;
	while (k >= 0)
	{
		if (arr[col][k] > max)
		{
			max = arr[col][k];
			sight--;
		}
		k--;
	}
	if (sight != 0)
		return (0);
	return (1);
}

int	ft_valid(int **arr, int *sight)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!chk_row_top(arr, sight[i], i)
			|| !chk_row_bot(arr, sight[i + 4], i)
			|| !chk_col_right(arr, sight[i + 12], i)
			|| !chk_col_left(arr, sight[i + 8], i))
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < 16)
	{
		if (!board_row_check(arr, i) || !board_column_check(arr, i))
			return (0);
		i++;
	}
	return (1);
}
