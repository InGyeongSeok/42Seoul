/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:58:26 by inseok            #+#    #+#             */
/*   Updated: 2023/03/26 14:30:23 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*save;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		save = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = save;
	}
}
