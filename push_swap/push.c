/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:42:20 by inseok            #+#    #+#             */
/*   Updated: 2023/09/17 16:04:28 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, char *print)
{
	ft_printf("%s\n", print);
	push(stack_a, pop(stack_b));
}

void	pb(t_stack *stack_a, t_stack *stack_b, char *print)
{
	ft_printf("%s\n", print);
	push(stack_b, pop(stack_a));
}
