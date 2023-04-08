/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:31:16 by inseok            #+#    #+#             */
/*   Updated: 2023/03/31 15:45:32 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *neddle, size_t len)
{
	size_t	i;

	if (*neddle == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		while (*(haystack + i) == *(neddle + i) && i < len)
		{
			++i;
			if (*(neddle + i) == '\0')
				return ((char *)haystack);
		}
		len--;
		++haystack;
	}
	return (0);
}
