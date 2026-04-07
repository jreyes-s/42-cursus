/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide.oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 22:50:20 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/04/03 01:22:44 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_disorder_index(t_stack *stack)
{
	float	mistakes;
	float	total_pairs;
	t_node	*current;
	t_node	*compare;

	mistakes = 0;
	total_pairs = 0;
	if (!stack || stack->size < 2)
		return (0.0);
	current = stack->top;
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			total_pairs++;
			if (current->value > compare->value)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}
