/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:12:27 by inseok            #+#    #+#             */
/*   Updated: 2023/03/15 10:31:13 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*source, int num)
{
	int	i;

	i = 0;
	while (num)
	{
		((char *)dest)[i] = ((char *)source)[i];
		num--;
		i++;
	}
	return (dest);
}
