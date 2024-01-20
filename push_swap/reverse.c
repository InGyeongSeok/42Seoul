/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:42:47 by inseok            #+#    #+#             */
/*   Updated: 2023/09/17 16:04:43 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack, char *print)
{
	t_node	*tmp;

	if (stack->len < 2)
		return ;
	if (print)
		ft_printf("%s\n", print);
	tmp = stack->bottom;
	stack->bottom = tmp->prev;
	stack->bottom->next = NULL;
	stack->top->prev = tmp;
	tmp->next = stack->top;
	tmp->prev = NULL;
	stack->top = tmp;
}

void	rrr(t_stack *stack_a, t_stack *stack_b, char *print)
{
	reverse_rotate(stack_a, NULL);
	reverse_rotate(stack_b, NULL);
	if (print)
		ft_printf("%s\n", print);
}
