/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:35:05 by inseok            #+#    #+#             */
/*   Updated: 2023/06/25 14:37:20 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_u(va_list *ap)
{
	unsigned int	n;
	char			*s;
	int				count;

	n = (unsigned)va_arg(*ap, int);
	s = ft_itoa(n);
	if (!s)
		return (write(1, "(null)", 6));
	count = write(1, s, ft_strlen(s));
	free(s);
	return (count);
}
