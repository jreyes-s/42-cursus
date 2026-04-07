/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:59:18 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/04/05 23:44:47 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *stack_dest, t_stack *stack_src)
{
	t_node	*node_to_move;

	if (!stack_src || !stack_dest || !stack_src->top)
		return ;
	node_to_move = stack_src->top;
	stack_src->top = node_to_move->next;
	stack_src->size--;
	node_to_move->next = stack_dest->top;
	stack_dest->top = node_to_move;
	stack_dest->size++;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
