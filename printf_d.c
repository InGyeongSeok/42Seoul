/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:45:25 by inseok            #+#    #+#             */
/*   Updated: 2023/06/26 08:55:47 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_d(va_list *ap)
{
	int		n;
	char	*s;
	int		count;

	n = va_arg(*ap, int);
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
