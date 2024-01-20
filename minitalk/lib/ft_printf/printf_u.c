/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:35:05 by inseok            #+#    #+#             */
/*   Updated: 2023/07/29 11:40:59 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_u(va_list *ap)
{
	unsigned int	n;
	char			*s;
	int				count;

	n = (unsigned int)va_arg(*ap, int);
	s = printf_itoa(n);
	if (!s)
		return (-1);
	count = 0;
	while (s[count])
		count++;
	count = write(1, s, count);
	free(s);
	return (count);
}
