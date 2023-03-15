/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:31:16 by inseok            #+#    #+#             */
/*   Updated: 2023/03/15 15:50:20 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len != 0)
	{
		i = 0;
		while (*(big + i) == *(little + i) && i < len)
		{
			i++;
			if (*(little + i) == '\0')
				return ((char *)big);
		}
		big++;
	}
	return (0);
}
