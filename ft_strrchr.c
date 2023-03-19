/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:56:41 by inseok            #+#    #+#             */
/*   Updated: 2023/03/19 15:18:39 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = 0;
	if ((unsigned char)c == 0)
		return (&((char *)s)[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			last = &((char *)s)[i];
		i++;
	}
	return (last);
}
