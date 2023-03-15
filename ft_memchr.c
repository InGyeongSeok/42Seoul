/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:49:27 by inseok            #+#    #+#             */
/*   Updated: 2023/03/15 15:16:08 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	char	*src_temp;

	src_temp = (char *)src;
	while (n)
	{
		if (*src_temp == c)
			return (src_temp);
		n--;
		src_temp++;
	}
	return (0);
}
