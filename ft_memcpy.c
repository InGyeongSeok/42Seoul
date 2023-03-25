/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:12:27 by inseok            #+#    #+#             */
/*   Updated: 2023/03/25 09:26:26 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	int	i;

	i = 0;
	if ((char *)dst == (char *)src)
		return (dst);
	while (n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		n--;
		i++;
	}
	return (dst);
}
