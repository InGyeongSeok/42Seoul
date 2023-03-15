/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:52:26 by inseok            #+#    #+#             */
/*   Updated: 2023/03/15 10:05:30 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, int num)
{
	int	*a;

	a = ptr;
	while (num)
	{
		*a = value;
		a++;
		num--;
	}
	a -= num;
	return (a);
}
