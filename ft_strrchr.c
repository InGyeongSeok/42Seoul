/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:56:41 by inseok            #+#    #+#             */
/*   Updated: 2023/03/15 15:10:54 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*str, int c)
{
	char	*str_temp;
	char	*ptr;

	str_temp = (char *)str;
	while (*str_temp)
	{
		ptr = ft_strchr(str_temp, c);
		if (*str_temp + 1 == '\0')
		{
			return (ptr);
		}
		str_temp++;
	}
	return (0);
}
