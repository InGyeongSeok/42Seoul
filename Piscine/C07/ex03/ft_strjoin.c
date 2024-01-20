/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:58:07 by inseok            #+#    #+#             */
/*   Updated: 2023/01/27 20:36:13 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	all_len(int size, char **strs, char *sep)
{
	int	new_len;
	int	i;

	i = 0;
	new_len = 0;
	while (i < size -1)
	{
		new_len += ft_strlen(strs[i]);
		new_len += ft_strlen(sep);
		i++;
	}
	new_len += ft_strlen(strs[i]);
	return (new_len);
}

void	ft_putstr(char *str, char *new)
{
	int	i;

	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
}

char	*is_size(void)
{
	char	*new;

	new = (char *)malloc(1 * sizeof(char));
	new[0] = '\0';
	return (new);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		new_len;
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (size == 0)
		return (is_size());
	new_len = all_len(size, strs, sep);
	new = (char *)malloc((new_len + 1) * sizeof(char));
	if (new == 0)
		return (0);
	while (j < size -1)
	{
		ft_putstr(strs[j], new + i);
		i += ft_strlen(strs[j]);
		ft_putstr(sep, new + i);
		i += ft_strlen(sep);
		j++;
	}
	ft_putstr(strs[j], new + i);
	i += ft_strlen(strs[j]);
	new[i] = '\0';
	return (new);
}
