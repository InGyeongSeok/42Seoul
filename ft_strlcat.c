/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:27:41 by inseok            #+#    #+#             */
/*   Updated: 2023/03/19 10:45:53 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	unsigned int	destlen;
	unsigned int	srclen;
	unsigned int	i;

	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	while (src[i] && destlen + i + 1 < dstsize)
	{
		dst[destlen + i] = src[i];
		++i;
	}
	dst[destlen + i] = '\0';
	if (destlen < dstsize)
		return (srclen + destlen);
	return (srclen + dstsize);
}
