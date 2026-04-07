/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide.oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:05:21 by tide.oli          #+#    #+#             */
/*   Updated: 2026/04/02 01:07:23 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stacker(int value, t_stack *stack_a)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	if (!stack_a->top)
	{
		stack_a->top = new_node;
		stack_a->last = new_node;
	}
	else
	{
		stack_a->last->next = new_node;
		stack_a->last = new_node;
	}
	stack_a->size++;
}

void	ft_push_swap(int mode, t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	if (mode == 1)
		medium_algorithm(stack_a, stack_b);
	else if (mode == 0 || mode == 4)
		simple_algorithm(stack_a, stack_b);
	else
		simple_algorithm(stack_a, stack_b);
}
