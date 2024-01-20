/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:30:33 by inseok            #+#    #+#             */
/*   Updated: 2023/01/21 21:30:29 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

int	isbase(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(long long c, char *base)
{
	write(1, base + c, 1);
}

void	ft_renbr(long long renbr, long long count, char *base)
{
	if (renbr < count)
	{
		ft_putchar(renbr, base);
	}
	else if (renbr >= count)
	{
		ft_renbr(renbr / count, count, base);
		ft_renbr(renbr % count, count, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	count;
	long long	renbr;
	int			i;

	count = 0;
	i = 0;
	renbr = (long long)nbr;
	if (isbase(base))
	{
		while (base[i])
		{
			count++;
			i++;
		}
	}
	if (count == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		renbr = renbr * -1;
	}
	ft_renbr(renbr, count, base);
}
