/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 14:02:43 by tide-oli          #+#    #+#             */
/*   Updated: 2026/03/19 17:02:21 by tide-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_eq(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (s1[i] == '\0' && s2[i] == '\0');
}

int	check_mode(char *argv)
{
	if (ft_isnumber(argv))
		return (4);
	else if (str_eq(argv, "--simple"))
		return (0);
	else if (str_eq(argv, "--medium"))
		return (1);
	else if (str_eq(argv, "--complex"))
		return (2);
	else if (str_eq(argv, "--adaptative") || str_eq(argv, "--adaptive"))
		return (3);
	else
	{
		write(2, "Error\n", 6);
		return (-1);
	}
}

int	entry_checker(char **argv, int index, t_stack *stack_a)
{
	long	number;

	number = 0;
	while (argv[index])
	{
		if (!ft_isnumber(argv[index]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		number = ft_atoi_long(argv[index]);
		if (number > INT_MAX || number < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		ft_stacker((int)number, stack_a);
		index++;
	}
	if (!check_duplicates(stack_a))
		return (0);
	return (1);
}

int	check_duplicates(t_stack *stack_a)
{
	t_node	*current;
	t_node	*runner;

	current = stack_a->top;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		mode;
	int		i;

	if (argc < 2)
		return (1);
	stack_a.top = NULL;
	stack_a.last = NULL;
	stack_a.size = 0;
	stack_b.top = NULL;
	stack_b.last = NULL;
	stack_b.size = 0;
	mode = check_mode(argv[1]);
	i = 1;
	if (mode < 0)
		return (1);
	if (mode != 4)
		i++;
	if (argc - i < 2)
		return (0);
	if (!entry_checker(argv, i, &stack_a))
		return (1);
	assignment_indices(&stack_a);
	ft_push_swap(mode, &stack_a, &stack_b);
	cleanup_stack(&stack_a);
	cleanup_stack(&stack_b);
	return (0);
}
