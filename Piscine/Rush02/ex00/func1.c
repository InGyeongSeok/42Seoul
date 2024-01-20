/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwoc <seongwoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:41:41 by seongwoc          #+#    #+#             */
/*   Updated: 2023/01/29 23:41:43 by seongwoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_space_colon(char c)
{
	if ((c >= 9 && c <= 13) || c == 32 || c == ':')
		return (1);
	return (0);
}

int	ft_strcmpone(char c, char *dict)
{	
	if (dict[0] == c && ft_is_space_colon(dict[1]))
		return (1);
	return (-1);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (s1[0] == s2[0] && s1[1] == s2[1] && ft_is_space_colon(s2[2]))
		return (1);
	return (-1);
}

int	ft_strcmpteen(char c1, char c2, char *s)
{
	if (s[0] == c1 && s[1] == c2 && ft_is_space_colon(s[2]))
		return (1);
	return (-1);
}
