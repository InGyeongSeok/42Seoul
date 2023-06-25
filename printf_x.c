/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:42:49 by inseok            #+#    #+#             */
/*   Updated: 2023/06/25 16:42:07 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_x(va_list *ap, const char format)
{
	char				*hex;
	char				mem[8];
	unsigned int		address;
	unsigned int		temp;
	int					i;

	address = (unsigned int)va_arg(*ap, int);
	i = 8;
	hex = "0123456789abcdef";
	if (format == 'X')
		hex = "0123456789ABCDEF";
	while (--i >= 0)
	{
		temp = address % 16;
		address = address / 16;
		mem[i] = *(hex + temp);
		if (address == 0)
			break ;
	}
	return (write(1, mem + i, 8 - i));
}
