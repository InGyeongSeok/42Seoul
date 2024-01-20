/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:22:59 by inseok            #+#    #+#             */
/*   Updated: 2023/01/15 14:00:54 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ischar(char *str)
{
	char	c;

	c = *str;
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capital;

	i = 0;
	capital = 1;
	while (str[i])
	{
		if (ischar(&str[i]))
		{
			if (capital == 1 && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 'a' + 'A';
			else if (capital == 0 && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] - 'A' + 'a';
			capital = 0;
		}
		else
			capital = 1;
		i++;
	}
	return (str);
}
