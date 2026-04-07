/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 04:07:00 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/04/06 06:39:16 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *stack_a)
{
	int		min_value;
	int		min_pos;
	int		current_pos;
	t_node	*current;

	if (!stack_a || !stack_a->top)
		return (-1);
	min_value = stack_a->top->value;
	min_pos = 0;
	current_pos = 0;
	current = stack_a->top;
	while (current != NULL)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_stack *stack_a)
{
	int	min_pos;

	min_pos = find_min_pos(stack_a);
	if (min_pos < 0)
		return ;
	if (min_pos <= stack_a->size / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < stack_a->size)
		{
			rra(stack_a);
			min_pos++;
		}
	}
}

static void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a || stack_a->size < 3)
		return ;
	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;
	if (a > b && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > c && b < c)
		ra(stack_a);
	else if (a < b && a > c)
		rra(stack_a);
	else if (a < c && b > c)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

static void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	move_min_to_top(stack_a);
	pb(stack_a, stack_b);
	move_min_to_top(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
}
