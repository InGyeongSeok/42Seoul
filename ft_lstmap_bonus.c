/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:42:14 by inseok            #+#    #+#             */
/*   Updated: 2023/03/26 15:53:31 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*save_node;
	t_list	*new_list;
	void	*new_content;

	if (!lst || !f)
		return (0);
	new_list = 0;
	while (lst)
	{
		new_content = f(lst->content);
		save_node = ft_lstnew(new_content);
		if (!save_node)
		{
			free(new_content);
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, save_node);
		lst = lst->next;
	}
	return (new_list);
}
