/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_indices.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 01:05:29 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/04/05 22:51:43 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index(int value, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

void	assignment_indices(t_stack *stack)
{
	int		*arr;
	t_node	*current;

	arr = get_sorted_arr(stack);
	if (!arr)
		return ;
	current = stack->top;
	while (current)
	{
		current->index = find_index(current->value, arr, stack->size);
		current = current->next;
	}
	free(arr);
}
