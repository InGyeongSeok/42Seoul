/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:38:39 by inseok            #+#    #+#             */
/*   Updated: 2023/02/02 00:12:23 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	add(int a, int b)
{
	ft_putnbr(a + b);
	write(1, "\n", 1);
}

void	sub(int a, int b)
{
	ft_putnbr(a - b);
	write(1, "\n", 1);
}

void	mul(int a, int b)
{
	ft_putnbr(a * b);
	write(1, "\n", 1);
}

void	div(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
	}	
	else
	{
		ft_putnbr(a / b);
		write(1, "\n", 1);
	}
}

void	mod(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
	}	
	else
	{
		ft_putnbr(a % b);
		write(1, "\n", 1);
	}
}
