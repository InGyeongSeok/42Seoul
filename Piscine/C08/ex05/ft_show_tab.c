/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:25:58 by inseok            #+#    #+#             */
/*   Updated: 2023/01/29 00:47:46 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putchar(char c)
{
	char	nb;

	nb = c + '0';
	write(1, &nb, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -1 * nb;
	}
	if (nb < 10)
	{
		ft_putchar(nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_show_tab(t_stock_str *p)
{
	int	i;

	i = 0;
	while (p[i].str != 0)
	{
		ft_putstr(p[i].str);
		ft_putstr("\n");
		ft_putnbr(p[i].size);
		ft_putstr("\n");
		ft_putstr(p[i].copy);
		ft_putstr("\n");
		i++;
	}
}
