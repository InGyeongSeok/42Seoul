/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:52:16 by inseok            #+#    #+#             */
/*   Updated: 2023/01/13 21:59:18 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

void	make_combn(int num, int index, int n, int combn[])
{
	int		i;

	if (index == n)
	{
		i = 0;
		while (i < index)
		{
			ft_putchar(combn[i]);
			i++;
		}
		if (combn[0] != 10 - n)
			write(1, ", ", 2);
		return ;
	}
	while (num <= 10 - n + index)
	{
		combn[index] = num;
		make_combn(num +1, index +1, n, combn);
		num++;
	}
}

void	ft_print_combn(int n)
{
	int		combn[9];

	make_combn(0, 0, n, combn);
}
