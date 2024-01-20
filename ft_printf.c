/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:04:05 by inseok            #+#    #+#             */
/*   Updated: 2023/06/26 09:00:57 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifier(const char format, va_list *ap)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = printf_c(ap);
	else if (format == 's')
		count = printf_s(ap);
	else if (format == 'p')
		count = printf_p(ap);
	else if (format == 'd' || format == 'i')
		count = printf_d(ap);
	else if (format == 'u')
		count = printf_u(ap);
	else if (format == 'x' || format == 'X')
		count = printf_x(ap, format);
	else if (format == '%')
		count = write(1, "%", 1);
	if (count == -1)
		return (-1);
	else
		return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	int		temp;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			temp = handle_specifier(format[++i], &ap);
		else
			temp = write(1, &format[i], 1);
		if (temp == -1)
			return (-1);
		else
			count += temp;
		i++;
	}
	va_end(ap);
	return (count);
}
