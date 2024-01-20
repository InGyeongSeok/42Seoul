/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:43:06 by inseok            #+#    #+#             */
/*   Updated: 2023/09/19 22:55:16 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 3)
		three_sort(stack_a);
	else if (stack_a->len == 2)
	{
		if (stack_a->top->data > stack_a->bottom->data)
			swap(stack_a, "sa");
	}
	else
		greedy_sort(stack_a, stack_b);
}

void	three_sort(t_stack *stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = stack_a->top->data;
	middle = stack_a->top->next->data;
	bottom = stack_a->bottom->data;
	if (top < middle && top < bottom)
	{
		reverse_rotate(stack_a, "rra");
		swap(stack_a, "sa");
	}
	else if (middle < top && middle < bottom)
	{
		if (top < bottom)
			swap(stack_a, "sa");
		else
			rotate(stack_a, "ra");
	}
	else
		three_sort_final(stack_a, top, middle);
}

void	three_sort_final(t_stack *stack_a, int top, int middle)
{
	if (top > middle)
	{
		swap(stack_a, "sa");
		reverse_rotate(stack_a, "rra");
	}
	else
		reverse_rotate(stack_a, "rra");
}
