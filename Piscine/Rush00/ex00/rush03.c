/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:15:52 by seunlee2          #+#    #+#             */
/*   Updated: 2023/01/15 20:10:12 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	w;
	int	h;

	h = 1;
	while (h <= y)
	{
		w = 1;
		while (w <= x)
		{
			if (w == 1 && (h == 1 || h == y))
				ft_putchar('A');
			else if ((h == 1 || h == y) && w == x)
				ft_putchar('C');
			else if ((h == 1 || h == y) && (1 < w && w < x))
				ft_putchar('B');
			else if (1 < h && h < y && (w == 1 || w == x))
				ft_putchar('B');
			else if (1 < h && h < y && (1 < w && w < x))
				ft_putchar(' ');
			w++;
		}
		ft_putchar('\n');
		h++;
	}
}
