/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:12:40 by inseok            #+#    #+#             */
/*   Updated: 2023/06/25 19:34:21 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_p(va_list *ap)
{
	char				*hex;
	char				mem[16];
	unsigned long long	address;
	unsigned long long	temp;
	int					i;

	address = (unsigned long long)va_arg(*ap, void *);
	i = 16;
	hex = "0123456789abcdef";
	while (--i >= 0)
	{
		temp = address % 16;
		address = address / 16;
		mem[i] = *(hex + temp);
		if (address == 0)
			break ;
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	return (write(1, mem + i, 16 - i) + 2);
}
