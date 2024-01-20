/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:14:08 by sanseo            #+#    #+#             */
/*   Updated: 2023/01/22 14:16:19 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_correct_input(int argc, char *argv[])
{
	int		i;

	if (argc != 2)
		return (0);
	i = 0;
	while (argv[1][i])
	{
		if (i % 2 == 0 && !(argv[1][i] >= '1' && argv[1][i] <= '4'))
			return (0);
		else if (i % 2 == 1 && argv[1][i] != ' ')
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

int	ft_atoi(char ch)
{
	return (ch - '0');
}

int	*split_str(char *str)
{
	int		i;
	int		*col_row_val;

	i = 0;
	col_row_val = 0;
	col_row_val = (int *)malloc(sizeof(int) * 16);
	while (*str)
	{
		if (*str <= '9' && *str >= '0')
		{
			col_row_val[i] = ft_atoi(*str);
			i++;
		}
		str++;
	}
	return (col_row_val);
}
