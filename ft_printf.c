/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:04:05 by inseok            #+#    #+#             */
/*   Updated: 2023/06/25 20:16:15 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handleSpecifier(const char format, va_list *ap)
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
	int	i;
	int	count;
	int	temp;

	i = 0;                //index
	count = 0;            //출력한 글자 수 반환
	va_list ap;           //가변 인자 목록을 ap에 담을 것이다.
	va_start(ap, format); //dcs라는 문자열의 개수 만큼 ap가 이동할 것.
	while (format[i])
	{
		if (format[i] == '%')
			temp = handleSpecifier(format[++i], &ap);
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
