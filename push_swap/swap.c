/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:13:35 by inseok            #+#    #+#             */
/*   Updated: 2023/09/17 16:13:39 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char *print)
{
	int	tmp;

	if (stack->len < 2)
		return ;
	if (print)
		ft_printf("%s\n", print);
	tmp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp;
}

void	ss(t_stack *stack_a, t_stack *stack_b, char *print)
{
	swap(stack_a, NULL);
	swap(stack_b, NULL);
	if (print)
		ft_printf("%s\n", print);
}
