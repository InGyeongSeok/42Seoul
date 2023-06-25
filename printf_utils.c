/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:05:41 by inseok            #+#    #+#             */
/*   Updated: 2023/06/25 18:00:35 by inseok           ###   ########.fr       */
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

static int	itoa_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*printf_itoa(long n)
{
	int		len;
	int		i;
	char	*result;

	len = itoa_len(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		result[0] = '0';
	i = len - 1;
	while (n)
	{
		result[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (result);
}
