/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:32:53 by inseok            #+#    #+#             */
/*   Updated: 2023/09/22 13:37:02 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_location(t_stack *stack_a, int n)
{
	if (n >= stack_a->top->data)
		return (big_n(stack_a, n));
	else
		return (small_n(stack_a, n));
}

int	big_n(t_stack *stack_a, int n)
{
	int		index;
	t_node	*tmp;

	index = 0;
	if (n > stack_a->bottom->data && stack_a->top->data < stack_a->bottom->data)
		return (0);
	tmp = stack_a->top;
	while (tmp->data < n && tmp->data >= stack_a->top->data)
	{
		tmp = tmp->next;
		index++;
	}
	if (index >= (stack_a->len + 1) / 2)
		index = index - stack_a->len;
	return (index);
}

int	small_n(t_stack *stack_a, int n)
{
	int		index;
	t_node	*tmp;

	index = 0;
	if (stack_a->bottom->data > stack_a->top->data)
		return (0);
	tmp = stack_a->bottom;
	while (tmp->data > n && tmp->data <= stack_a->bottom->data)
	{
		tmp = tmp->prev;
		index--;
	}
	if (index * -1 >= (stack_a->len + 1) / 2)
		index = index + stack_a->len;
	return (index);
}
