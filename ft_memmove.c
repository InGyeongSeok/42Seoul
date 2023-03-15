/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:34:38 by inseok            #+#    #+#             */
/*   Updated: 2023/03/15 10:51:47 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, int num)
{
	char	*dest_temp;
	char	*src_temp;
	int		i;

	i = 0;
	dest_temp = (char *)dest;
	src_temp = (char *)src;
	while (num)
	{
		dest_temp[i] = src_temp[i];
		num--;
		i++;
	}
	return (dest);
}
