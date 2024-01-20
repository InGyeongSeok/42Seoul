/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:39:37 by inseok            #+#    #+#             */
/*   Updated: 2023/09/17 16:38:41 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	node->next = stack->top;
	node->prev = NULL;
	if (!stack->len)
		stack->bottom = node;
	else
		stack->top->prev = node;
	stack->top = node;
	stack->len++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (!stack->len)
		return (NULL);
	node = stack->top;
	if (stack->bottom == node)
		stack->bottom = NULL;
	stack->top = node->next;
	if (node->next)
		node->next->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->len--;
	return (node);
}

void	push_back(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	node->prev = stack->bottom;
	node->next = NULL;
	if (!stack->len)
		stack->top = node;
	else
		stack->bottom->next = node;
	stack->bottom = node;
	stack->len++;
}

void	set_min_max(t_stack *stack_a)
{
	t_node	*tmp;

	tmp = stack_a->top;
	while (tmp)
	{
		if (tmp->data > stack_a->max)
			stack_a->max = tmp->data;
		if (tmp->data < stack_a->min)
			stack_a->min = tmp->data;
		tmp = tmp->next;
	}
}
