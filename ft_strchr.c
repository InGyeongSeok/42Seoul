/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:08:27 by inseok            #+#    #+#             */
/*   Updated: 2023/03/15 12:54:49 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	char	*str_temp;

	str_temp = (char *)str;
	while (str_temp)
	{
		if (*str_temp == c)
			return (str_temp);
		str_temp++;
	}
	return (0);
}
