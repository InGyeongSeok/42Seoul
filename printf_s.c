/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:53:04 by inseok            #+#    #+#             */
/*   Updated: 2023/06/26 08:55:15 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_s(va_list *ap)
{
	char	*s;
	int		count;

	s = (char *)va_arg(*ap, void *);
	if (!s)
		return (write(1, "(null)", 6));
	if (s[0] == '\0')
		return (0);
	count = 0;
	while (s[count])
		count++;
	count = write(1, s, count);
	return (count);
}
