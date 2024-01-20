/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:55:44 by inseok            #+#    #+#             */
/*   Updated: 2023/06/26 08:59:01 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_c(va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	return (write(1, &c, 1));
}