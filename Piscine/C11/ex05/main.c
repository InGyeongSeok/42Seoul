/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:14:25 by inseok            #+#    #+#             */
/*   Updated: 2023/02/01 23:49:35 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi(char *str)
{
	int	minus;
	int	num;

	minus = 0;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (minus % 2 == 1)
		num *= -1;
	return (num);
}

int	is_right(char c)
{
	if (c == '+' || c == '-' || c == '*')
		return (1);
	else if (c == '/' || c == '%')
		return (1);
	else
		return (-1);
}

int	main(int argc, char *argv[])
{
	int		a;
	int		b;

	if (argc != 4)
		return (0);
	if (is_right(argv[2][0]) == -1 || argv[2][1])
	{
		write(1, "0\n", 2);
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	math_result(a, b, argv[2][0]);
	return (0);
}

int	math_result(int a, int b, char c)
{
	void	(*f[5])(int, int);

	f[0] = add;
	f[1] = sub;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	if (c == '+')
		f[0](a, b);
	else if (c == '-')
		f[1](a, b);
	else if (c == '*')
		f[2](a, b);
	else if (c == '/')
		f[3](a, b);
	else if (c == '%')
		f[4](a, b);
	return (0);
}
