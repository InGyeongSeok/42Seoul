/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:59:20 by inseok            #+#    #+#             */
/*   Updated: 2023/01/31 19:45:01 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_exist(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, char *base, int count)
{
	int	minus;
	int	num;

	minus = 0;
	num = 0;
	while (*str)
	{
		while ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				minus++;
			str++;
		}
		while (is_exist(*str, base) != -1)
		{
			num = num * count + is_exist(*str, base);
			str++;
		}
		if (minus % 2 == 1)
			num *= -1;
		return (num);
	}
	return (0);
}

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
		if ((base[i] <= 13 && base[i] >= 9) || base[i] == 32)
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

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	count;
	int				num;
	int				i;

	count = 0;
	i = 0;
	if (isbase(base))
	{
		while (base[i])
		{
			count++;
			i++;
		}
		num = ft_atoi(str, base, count);
		return (num);
	}
	return (0);
}
