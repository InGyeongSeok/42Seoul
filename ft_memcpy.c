/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:12:27 by inseok            #+#    #+#             */
/*   Updated: 2023/03/19 10:35:30 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	int	i;

	i = 0;
	while (n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		n--;
		i++;
	}
	return (dst);
}
