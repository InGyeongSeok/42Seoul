/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:14:55 by inseok            #+#    #+#             */
/*   Updated: 2023/03/15 15:24:06 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s1_temp;
	char	*s2_temp;
	int		diff;

	s1_temp = (char *)s1;
	s2_temp = (char *)s2;
	while (n)
	{
		diff = *s1_temp - *s2_temp;
		if (diff != 0)
			return (diff);
		else
		{
			s1_temp++;
			s2_temp++;
		}
	}
	return (0);
}
