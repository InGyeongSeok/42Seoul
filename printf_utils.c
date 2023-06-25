/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:05:41 by inseok            #+#    #+#             */
/*   Updated: 2023/06/25 13:40:11 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;

	i = 0;
	while (len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		len--;
		i++;
	}
	return (b);
}
