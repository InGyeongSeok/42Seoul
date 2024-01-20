/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:27:23 by inseok            #+#    #+#             */
/*   Updated: 2023/09/19 22:55:40 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	a_best;
	int	b_best;

	if (stack_a->len > 100)
		divide(stack_a, stack_b);
	while (stack_a->len > 3)
		pb(stack_a, stack_b, "pb");
	if (!(stack_a->top->data < stack_a->top->next->data
			&& stack_a->top->next->data < stack_a->bottom->data))
		three_sort(stack_a);
	while (stack_b->len)
	{
		a_best = 0;
		b_best = 0;
		count_best(stack_a, stack_b, &a_best, &b_best);
		do_rotate(stack_a, stack_b, a_best, b_best);
		pa(stack_a, stack_b, "pa");
	}
	rotate_final(stack_a);
}

void	rotate_final(t_stack *stack)
{
	int		index;
	t_node	*tmp;

	index = 0;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->data == stack->min)
		{
			if (index > (stack->len + 1) / 2)
			{
				while (++index < stack->len + 1)
					reverse_rotate(stack, "rra");
				return ;
			}
			else
			{
				while (--index >= 0)
					rotate(stack, "ra");
				return ;
			}
		}
		tmp = tmp->next;
		index++;
	}
}

void	count_best(t_stack *stack_a, t_stack *stack_b, int *a, int *b)
{
	t_node	*tmp;
	int		a_location;
	int		b_location;

	tmp = stack_b->top;
	b_location = 0;
	while (tmp)
	{
		a_location = find_location(stack_a, tmp->data);
		if (b_location >= (stack_b->len + 1) / 2)
			b_location = b_location - stack_b->len;
		if (b_location == 0 || sum(*a, *b) > sum(a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		tmp = tmp->next;
		b_location++;
	}
}

void	divide(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	pivot1;
	int	pivot2;

	pivot1 = (stack_a->max + stack_a->min) / 3;
	pivot2 = (stack_a->max + stack_a->min) * 2 / 3;
	i = stack_a->len;
	while (--i > 3)
	{
		if (stack_a->top->data < pivot1)
		{
			pb(stack_a, stack_b, "pb");
			rotate(stack_b, "rb");
		}
		else if (stack_a->top->data < pivot2)
		{
			pb(stack_a, stack_b, "pb");
		}
		else
			rotate(stack_a, "ra");
	}
}

int	sum(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}
