/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:04:05 by inseok            #+#    #+#             */
/*   Updated: 2023/06/25 18:16:40 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handleSpecifier(const char format, va_list* ap)
{
	if (format == 'c')
		return (printf_c(ap));
	else if (format == 's')
		return (printf_s(ap));
	else if (format == 'p')
		return (printf_p(ap));
	else if (format == 'd' || format == 'i')
		return (printf_d(ap));
	else if (format == 'u')
		return (printf_u(ap));
	else if(format == 'x' || format == 'X')
		return (printf_x(ap, format));
	else if(format == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	count;

	i = 0;      //index
	count = 0;  //����� ���� �� ��ȯ
	va_list ap; //���� ���� ����� ap�� ���� ���̴�.
	va_start(ap, format); //dcs��� ���ڿ��� ���� ��ŭ ap�� �̵��� ��.
	while (format[i])
	{
		if (format[i] == '%'){
			i++;
			count += handleSpecifier(format[i], &ap);
		}
		else
			count += write(1, &format[i], 1);
			// if(write(1, &format[i], 1) == -1)
			// 	return (-1);
			// else
			// 	count++;
		i++;
	}
	va_end(ap);
	return (count);
}
