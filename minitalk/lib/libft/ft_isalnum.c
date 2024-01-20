/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:35:16 by inseok            #+#    #+#             */
/*   Updated: 2023/03/19 10:11:42 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1)
		return (1);
	else if (ft_isalpha(c) == 1)
		return (1);
	else if (ft_isdigit(c) == 1)
		return (1);
	else
		return (0);
}
