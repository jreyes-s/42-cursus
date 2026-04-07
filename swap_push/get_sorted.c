/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 06:07:23 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/04/06 06:07:39 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_sorted_arr(t_stack *stack_a)
{
	int		*arr;
	t_node	*current;
	int		i;

	if (!stack_a || stack_a->size < 2)
		return (NULL);
	arr = malloc(sizeof(int) * (stack_a->size));
	if (!arr)
		return (NULL);
	i = 0;
	current = stack_a->top;
	while (current)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	bubble_sort(arr, stack_a->size);
	return (arr);
}
