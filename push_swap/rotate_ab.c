/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:30:08 by inseok            #+#    #+#             */
/*   Updated: 2023/09/17 16:30:32 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	same_rotate(t_stack *stack_a, t_stack *stack_b, int *a, int *b)
{
	while (*a && *b)
	{
		if (*a > 0 && *b > 0)
		{
			rr(stack_a, stack_b, "rr");
			(*a)--;
			(*b)--;
		}
		else if (*a < 0 && *b < 0)
		{
			rrr(stack_a, stack_b, "rrr");
			(*a)++;
			(*b)++;
		}
		else
			break ;
	}
}

void	rotate_a(t_stack *stack_a, int *a)
{
	while (*a)
	{
		if (*a > 0)
		{
			rotate(stack_a, "ra");
			(*a)--;
		}
		else
		{
			reverse_rotate(stack_a, "rra");
			(*a)++;
		}
	}
}

void	rotate_b(t_stack *stack_b, int *b)
{
	while (*b)
	{
		if (*b > 0)
		{
			rotate(stack_b, "rb");
			(*b)--;
		}
		else
		{
			reverse_rotate(stack_b, "rrb");
			(*b)++;
		}
	}
}

void	do_rotate(t_stack *stack_a, t_stack *stack_b, int a, int b)
{
	same_rotate(stack_a, stack_b, &a, &b);
	rotate_a(stack_a, &a);
	rotate_b(stack_b, &b);
}
