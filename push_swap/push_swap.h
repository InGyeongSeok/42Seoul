/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:41:04 by inseok            #+#    #+#             */
/*   Updated: 2023/09/22 13:37:16 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

typedef struct s_node
{
	struct s_node	*prev;
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		len;
	int		min;
	int		max;
}	t_stack;

//stack.c
t_stack	*init_stack(void);
t_node	*create_node(int n);
void	free_stack(t_stack *stack);

//base.c
void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
void	push_back(t_stack *stack, t_node *node);
void	set_min_max(t_stack *stack_a);

//swap.c
void	swap(t_stack *stack, char *print);
void	ss(t_stack *stack_a, t_stack *stack_b, char *print);

//push.c
void	pa(t_stack *stack_a, t_stack *stack_b, char *print);
void	pb(t_stack *stack_a, t_stack *stack_b, char *print);

//rotate.c
void	rotate(t_stack *stack, char *print);
void	rr(t_stack *stack_a, t_stack *stack_b, char *print);

//reverse.c
void	reverse_rotate(t_stack *stack, char *print);
void	rrr(t_stack *stack_a, t_stack *stack_b, char *print);

//parse.c
void	check_duplicate(t_stack *stack);
void	issorted(t_stack *stack);
void	parse_argv(char **argv, t_stack *stack);
void	parse_error(void);

//parse_utils.c
void	is_int(char *str);
ssize_t	atol(const char *str);
void	is_empty(char *str);
void	is_digit(char *str);

//sort.c
void	sort(t_stack *stack_a, t_stack *stack_b);
void	three_sort(t_stack *stack_a);
void	three_sort_final(t_stack *stack_a, int top, int middle);

//greedy_sort.c
void	greedy_sort(t_stack *stack_a, t_stack *stack_b);
void	count_best(t_stack *stack_a, t_stack *stack_b, int *a, int *b);
void	divide(t_stack *stack_a, t_stack *stack_b);
int		sum(int a, int b);
void	rotate_final(t_stack *stack);

//rotate_ab.c
void	do_rotate(t_stack *stack_a, t_stack *stack_b, int a, int b);
void	same_rotate(t_stack *stack_a, t_stack *stack_b, int *a, int *b);
void	rotate_a(t_stack *stack_a, int *a);
void	rotate_b(t_stack *stack_b, int *b);

//find_a.c
int		find_location(t_stack *stack_a, int n);
int		big_n(t_stack *stack_a, int n);
int		small_n(t_stack *stack_a, int n);

#endif