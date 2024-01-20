/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:00:44 by inseok            #+#    #+#             */
/*   Updated: 2023/03/31 16:25:39 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*makeone(void)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * 1);
	if (!result)
		return (0);
	result[0] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;
	int		i;

	if (!s1 || !set)
		return (0);
	if ((*s1 == '\0' && *set == '\0') || *s1 == '\0')
		return (makeone());
	end = ft_strlen(s1);
	start = 0;
	i = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (0);
	while (start < end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}
