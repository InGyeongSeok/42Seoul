/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:45:41 by inseok            #+#    #+#             */
/*   Updated: 2023/09/16 21:12:04 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	plus;
	int	num;

	plus = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			plus = 0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 - (*str - '0');
		str++;
	}
	if (plus)
		num *= -1;
	return (num);
}
