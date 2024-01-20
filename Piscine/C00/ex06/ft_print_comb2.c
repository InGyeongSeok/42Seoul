/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:04:04 by inseok            #+#    #+#             */
/*   Updated: 2023/01/13 21:58:52 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	test(char *arr, int a, int b)
{
	arr[0] = a / 10 + '0';
	arr[1] = a % 10 + '0';
	arr[2] = ' ';
	arr[3] = b / 10 + '0';
	arr[4] = b % 10 + '0';
}

void	ft_print_comb2(void)
{
	char	arr[5];
	int		a;
	int		b;

	a = 0;
	b = a + 1;
	while (a < 98)
	{
		if (b > 99)
		{
			if (a != 98)
			{
				a++;
				b = a + 1;
			}
		}
		test(arr, a, b);
		write(1, &arr, 5);
		if (a != 98 && b != 100)
			write(1, ", ", 2);
		b++;
	}
}
