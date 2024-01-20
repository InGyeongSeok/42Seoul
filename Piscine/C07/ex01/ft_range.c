/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:04:46 by inseok            #+#    #+#             */
/*   Updated: 2023/01/26 15:54:02 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*num;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	num = (int *)malloc((max - min) * sizeof(int));
	if (num == 0)
		return (0);
	while (max - min)
	{
		num[i] = min;
		min++;
		i++;
	}
	return (num);
}
