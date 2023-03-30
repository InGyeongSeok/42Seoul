/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:38:34 by inseok            #+#    #+#             */
/*   Updated: 2023/03/30 08:43:55 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_count(int nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static char	*make_arr(int num, int nbr)
{
	char	*arr;

	if (nbr < 0)
	{
		arr = (char *)malloc((num + 2) * sizeof(char));
		if (!arr)
			return (0);
		arr[0] = '-';
		arr[num + 1] = '\0';
	}
	else
	{
		arr = (char *)malloc((num + 1) * sizeof(char));
		if (!arr)
			return (0);
		arr[num] = '\0';
	}
	return (arr);
}

static void	ft_renbr(long long nbr, char **arr)
{
	if (nbr < 10)
	{
		**arr = nbr + '0';
		++*arr;
	}
	else if (nbr >= 10)
	{
		ft_renbr(nbr / 10, arr);
		ft_renbr(nbr % 10, arr);
	}
}

char	*iszero(void)
{
	char	*arr;

	arr = (char *)malloc(2 * sizeof(char));
	if (!arr)
		return (0);
	arr[0] = '0';
	arr[1] = '\0';
	return (arr);
}

char	*ft_itoa(int n)
{
	long long	nbr;
	char		*arr;
	char		*result;
	int			num;

	nbr = (long long)n;
	if (nbr == 0)
	{
		result = iszero();
		if (!result)
			return (0);
		return (result);
	}
	num = num_count(nbr);
	result = make_arr(num, nbr);
	if (!result)
		return (0);
	arr = result;
	if (nbr < 0)
	{
		arr++;
		nbr *= -1;
	}
	ft_renbr(nbr, &arr);
	return (result);
}
