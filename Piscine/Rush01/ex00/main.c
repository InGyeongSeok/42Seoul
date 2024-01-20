/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:46:38 by sanseo            #+#    #+#             */
/*   Updated: 2023/01/22 22:47:13 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		check_correct_input(int argc, char *argv[]);
int		*split_str(char *str);
int		find_value(int *col_row_val);
int		check_all(int **ck);
int		**change(int **ck, int i);
int		board_row_check(int **board, int value);
int		board_column_check(int **board, int value);
int		ft_valid(int **arr, int *sight);
void	print(int **board);
int		**change_top(int **ck);

int	*str_to_int_arr(int argc, char *argv[])
{
	if (check_correct_input(argc, argv))
		return (split_str(argv[1]));
	else
		return (0);
}

int	main(int argc, char *argv[])
{	
	int		*a;

	a = str_to_int_arr(argc, argv);
	if (!a)
		write(1, "Error\n", 6);
	else
	{
		if (!find_value(a))
			write (1, "Error\n", 6);
	}
	return (0);
}

int	**init_arr(int **arr)
{
	int	i;

	arr = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
		arr[i++] = (int *)malloc(sizeof(int) * 4);
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[0][3] = 4;
	arr[1][0] = 2;
	arr[1][1] = 1;
	arr[1][2] = 4;
	arr[1][3] = 3;
	arr[2][0] = 3;
	arr[2][1] = 4;
	arr[2][2] = 1;
	arr[2][3] = 2;
	arr[3][0] = 4;
	arr[3][1] = 3;
	arr[3][2] = 2;
	arr[3][3] = 1;
	return (arr);
}

int	find_value(int *col_row_val)
{
	int		i;
	int		**ck;

	ck = 0;
	ck = init_arr(ck);
	i = 0;
	while (check_all(ck))
	{
		ck[3][3]++;
		ck = change_top(ck);
		if (ck[3][3] == 5)
			ck = change(ck, 14);
		if (!board_row_check(ck, 15) || !board_column_check(ck, 15))
			continue ;
		if (ft_valid(ck, col_row_val))
		{			
			print(ck);
			free(ck);
			free(col_row_val);
			return (1);
		}
	}
	free(ck);
	free(col_row_val);
	return (0);
}

int	**change_top(int **ck)
{
	int	i;

	i = 0;
	while (!board_row_check(ck, 3))
	{
		ck[0][3]++;
		if (ck[0][3] >= 5)
			ck = change(ck, 2);
	}
	return (ck);
}
