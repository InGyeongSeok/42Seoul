/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:46:52 by inseok            #+#    #+#             */
/*   Updated: 2023/01/29 00:28:37 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*make_arr(int *num, int nbr);
int		isbase(char *base);
int		num_count(int nbr, int count);
int		ft_atoi_base(char *str, char *base);
int		isbase(char *base);

void	ft_renbr(long long renbr, long long count, char *base, char **arr)
{
	if (renbr < count)
	{
		**arr = base[renbr];
		++*arr;
	}
	else if (renbr >= count)
	{
		ft_renbr(renbr / count, count, base, arr);
		ft_renbr(renbr % count, count, base, arr);
	}
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long long	count;
	long long	renbr;
	char		*arr;
	char		*result;
	int			num[1];

	count = 0;
	num[0] = 0;
	renbr = (long long)nbr;
	if (isbase(base))
		while (base[count])
			count++;
	else
		return (0);
	num[0] = num_count(nbr, count);
	result = make_arr(num, renbr);
	arr = result;
	if (renbr < 0)
	{
		arr++;
		renbr *= -1;
	}	
	ft_renbr(renbr, count, base, &arr);
	return (result);
}

int	num_count(int nbr, int count)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr /= count;
		i++;
	}
	return (i);
}

char	*make_arr(int *num, int nbr)
{
	char	*arr;

	if (nbr < 0)
	{
		arr = (char *)malloc((*num + 2) * sizeof(char));
		arr[0] = '-';
		arr[*num + 1] = 0;
	}
	else
	{
		arr = (char *)malloc((*num + 1) * sizeof(char));
		arr[*num] = 0;
	}
	return (arr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*arr;

	if (isbase(base_from) == -1 || isbase(base_to) == -1)
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	arr = ft_putnbr_base(num, base_to);
	return (arr);
}
