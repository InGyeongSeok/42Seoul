/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:39:13 by inseok            #+#    #+#             */
/*   Updated: 2023/01/12 15:08:07 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	arr[3];

	arr[0] = '0';
	while (arr[0] <= '7')
	{
		arr[1] = arr[0] +1;
		while (arr[1] <= '8')
		{
			arr[2] = arr[1] +1;
			while (arr[2] <= '9')
			{
				write(1, &arr[0], 1);
				write(1, &arr[1], 1);
				write(1, &arr[2], 1);
				if (arr[0] != '7')
					write(1, ", ", 2);
				arr[2]++;
			}
			arr[1]++;
		}
		arr[0]++;
	}
}