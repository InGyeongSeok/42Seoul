/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:50:36 by inseok            #+#    #+#             */
/*   Updated: 2023/06/25 14:55:30 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	count;
	int	count2;

	count = ft_printf("%x\n", 10);
	count2 = printf("%x\n", 10);
	printf("Total characters printed: %d\n", count);
	printf("Total characters printed: %d\n", count2);
	return (0);
}
