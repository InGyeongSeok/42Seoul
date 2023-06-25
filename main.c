/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:50:36 by inseok            #+#    #+#             */
/*   Updated: 2023/06/25 21:45:28 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>



int	main(void)
{
	int	count;
	int	count2;

	count = ft_printf("%d", 0);
	count2 = printf("%d", 0);
	printf("Total characters printed: %d\n", count);
	printf("Total characters printed: %d\n", count2);
	return (0);
}
