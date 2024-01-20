/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:34:13 by inseok            #+#    #+#             */
/*   Updated: 2023/09/17 16:23:38 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	atol(const char *str)
{
	int		plus;
	ssize_t	num;

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

void	is_int(char *str)
{
	int		i;
	ssize_t	num;

	i = -1;
	num = atol(str);
	while (str[++i])
	{
		if ((str[0] == '+' && i > 10) || (str[0] == '-' && i > 11)
			|| (ft_isdigit(str[0]) && i > 9))
			parse_error();
	}
	if (num > 2147483647 || num < -2147483648)
		parse_error();
}

void	is_empty(char *str)
{
	int	i;

	i = -1;
	if (!str)
		parse_error();
	while (str[++i])
	{
		if (str[i] != ' ')
			return ;
	}
	parse_error();
}

void	is_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && (str[i] != '+' && str[i] != '-'))
			parse_error();
		if ((str[i] == '+' || str[i] == '-') && i != 0)
			parse_error();
		if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
			parse_error();
	}
}
