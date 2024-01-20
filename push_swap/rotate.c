/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:42:57 by inseok            #+#    #+#             */
/*   Updated: 2023/09/17 16:04:49 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char *print)
{
	t_node	*tmp;

	if (stack->len < 2)
		return ;
	if (print)
		ft_printf("%s\n", print);
	tmp = stack->top;
	stack->top = tmp->next;
	tmp->next->prev = NULL;
	stack->bottom->next = tmp;
	tmp->prev = stack->bottom;
	stack->bottom = tmp;
	tmp->next = NULL;
}

void	rr(t_stack *stack_a, t_stack *stack_b, char *print)
{
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	if (print)
		ft_printf("%s\n", print);
}
