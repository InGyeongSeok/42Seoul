/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:13:15 by inseok            #+#    #+#             */
/*   Updated: 2023/09/25 17:28:27 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->bottom = NULL;
	stack->len = 0;
	stack->min = 2147483647;
	stack->max = -2147483648;
	return (stack);
}

t_node	*create_node(int n)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->prev = NULL;
	new_node->data = n;
	new_node->next = NULL;
	return (new_node);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*free_tmp;

	tmp = stack->top;
	while (tmp)
	{
		free_tmp = tmp;
		tmp = tmp->next;
		free(free_tmp);
	}
	free(stack);
}
