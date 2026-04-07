/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 22:16:12 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/04/06 06:09:03 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*last;
	int				size;
}					t_stack;

// Funciones
int					ft_isnumber(char *str);
int					check_mode(char *argv);
int					entry_checker(char **argv, int index, t_stack *stack_a);
int					check_duplicates(t_stack *stack_a);
void				ft_stacker(int number, t_stack *stack_a);
void				ft_push_swap(int mode, t_stack *stack_a, t_stack *stack_b);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);
float				ft_disorder_index(t_stack *stack);
long				ft_atoi_long(char *str);
void				assignment_indices(t_stack *stack_a);
void				simple_algorithm(t_stack *stack_a, t_stack *stack_b);
void				medium_algorithm(t_stack *stack_a, t_stack *stack_b);
void				cleanup_stack(t_stack *stack);
int					is_sorted(t_stack *stack_a);
int					*get_sorted_arr(t_stack *stack);
void				bubble_sort(int *arr, int size);

#endif
