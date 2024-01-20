/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 02:16:34 by inseok            #+#    #+#             */
/*   Updated: 2023/01/13 02:26:09 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	num;

	start = 0;
	while (start < size / 2)
	{
		num = tab[start];
		tab[start] = tab[size - 1 - start];
		tab[size - 1 - start] = num;
		start++;
	}
}
