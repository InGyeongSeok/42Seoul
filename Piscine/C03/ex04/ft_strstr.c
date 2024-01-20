/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:23:30 by inseok            #+#    #+#             */
/*   Updated: 2023/01/16 17:37:32 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		index;

	index = 0;
	if (*to_find == '\0')
		return (str);
	while (*str)
	{	
		index = 0;
		while (*(str + index) == *(to_find + index))
		{	
			++index;
			if (*(to_find + index) == '\0')
				return (str);
		}
		++str;
	}
	return (0);
}
