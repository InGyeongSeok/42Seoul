/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:42:14 by inseok            #+#    #+#             */
/*   Updated: 2023/03/26 11:04:06 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		size;
	t_list	*result;
	t_list	*save;

	save = lst;
	size = 0;
	while (save)
	{
		size++;
	}
	result = (t_list *)malloc(sizeof(t_list) * size);
	if (!result)
		return (0);
	while (lst)
	{
		result->content = f(lst->content);
		result = result->next;
		lst = lst->next;
		del(lst->content);
	}
	return (result);
}
