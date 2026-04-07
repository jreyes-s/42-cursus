/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 01:20:55 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/04/06 06:37:37 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_position(t_stack *stack_a)
{
	int		max_value;
	int		max_pos;
	int		current_pos;
	t_node	*current;

	if (!stack_a || !stack_a->top)
		return (-1);
	max_value = stack_a->top->value;
	max_pos = 0;
	current_pos = 0;
	current = stack_a->top;
	while (current != NULL)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (max_pos);
}

static void	push_to_b(t_stack *stack_a, t_stack *stack_b, int range)
{
	int	i;

	i = 0;
	if (!stack_a || !stack_b)
		return ;
	while (stack_a->top)
	{
		if (stack_a->top->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if (stack_a->top->index <= (i + range))
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

static void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	max_pos;

	while (stack_b->top)
	{
		max_pos = find_max_position(stack_b);
		if (max_pos <= stack_b->size / 2)
		{
			while (max_pos-- > 0)
				rb(stack_b);
		}
		else
		{
			while (max_pos++ < stack_b->size)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	medium_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	int	range;

	if (!stack_a || is_sorted(stack_a))
		return ;
	assignment_indices(stack_a);
	if (stack_a->size <= 100)
		range = 15;
	else
		range = 30;
	push_to_b(stack_a, stack_b, range);
	push_back_to_a(stack_a, stack_b);
}
