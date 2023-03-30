/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:12:27 by inseok            #+#    #+#             */
/*   Updated: 2023/03/30 00:40:17 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		n--;
		i++;
	}
	return (dst);
}
