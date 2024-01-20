/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:19:33 by inseok            #+#    #+#             */
/*   Updated: 2023/02/01 13:04:02 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag;	

	i = 0;
	flag = 0;
	while (i < length -1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
		{
			if (flag == 2)
				return (0);
			flag = 1;
		}
		if ((*f)(tab[i], tab[i + 1]) > 0)
		{
			if (flag == 1)
				return (0);
			flag = 2;
		}
		i++;
	}
	return (1);
}
