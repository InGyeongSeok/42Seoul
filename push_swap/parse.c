/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:40:50 by inseok            #+#    #+#             */
/*   Updated: 2023/09/25 17:38:50 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(t_stack *stack)
{
	t_node	*i;
	t_node	*j;

	i = stack->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->data == j->data)
			{
				free_stack(stack);
				parse_error();
			}
			j = j->next;
		}
		i = i->next;
	}
}

void	issorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return ;
		tmp = tmp->next;
	}
	free_stack(stack);
	exit(0);
}

void	parse_argv(char **argv, t_stack *stack)
{
	char		**arr;
	int			i;
	int			j;
	t_node		*new_node;

	i = 0;
	while (argv[++i])
	{
		is_empty(argv[i]);
		arr = ft_split(argv[i], ' ');
		j = -1;
		while (arr[++j])
		{
			is_digit(arr[j]);
			is_int(arr[j]);
			new_node = create_node(ft_atoi(arr[j]));
			push_back(stack, new_node);
			free(arr[j]);
		}
		free(arr);
	}
}

void	parse_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
