/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:03:12 by seonglim          #+#    #+#             */
/*   Updated: 2023/11/04 05:59:45 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long	my_atol(const char *str)
{
	long	num;
	long	plus;

	num = 0;
	plus = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		++str;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			plus = 0;
	while (*str >= '0' && *str <= '9')
		num = num * 10 - *str++ + '0';
	if (plus)
		num *= -1;
	return (num);
}

int	is_valid_digit(char *str)
{
	long	num;
	long	plus;

	num = 0;
	plus = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		++str;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			plus = 0;
	while (1)
	{
		if (*str >= '0' && *str <= '9')
			num = num * 10 - *str++ + '0';
		else if (!*str)
			break ;
		else
			return (0);
		if (num > 0)
			return (0);
		if (plus && num == -9223372036854775807L - 1L)
			return (0);
	}
	return (1);
}

void	builtin_exit(char **cmds)
{
	if (!cmds[1])
		exit(EXIT_SUCCESS);
	if (!is_valid_digit(cmds[1]))
	{
		ft_putstr_fd(sum_msg("gsh: exit: ", cmds[1], 0), 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	if (cmds[2])
	{
		ft_putstr_fd("gsh: exit: too many arguments\n", 2);
		exit_code(1, 1);
		return ;
	}
	exit(my_atol(cmds[1]));
}
