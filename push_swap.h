/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:49:58 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/20 07:08:27 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define STACK_SIZE 100
# define ERROR_ALLOC "A memory allocation error has occurred."
# define EMPTY_STACK "The stack is empty."
# define STACK_IS_EMPTY "The stack is now empty."

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

// ############# UTILS ############# //
int					is_empty(t_stack *stack);
long int			ft_atoi(const char *str);
void				message(const char *str);

// ############# CORE ############# //
int					pop(t_stack **stack);
void				sa(int *arr_a, int size_a);
void				sb(int *arr_b, int size_b);
void				ss(int *arr_a, int size_a, int *arr_b, int size_b);
void				pa(int *arr_a, int *size_a, int *arr_b, int *size_b);
void				pb(int *arr_a, int *size_a, int *arr_b, int *size_b);
void				ra(int *arr_a, int size_a);
void				rb(int *arr_b, int size_b);
void				rr(int *arr_a, int size_a, int *arr_b, int size_b);
void				rra(int *arr_a, int size_a);
void				rrb(int *arr_b, int size_b);
void				rrr(int *arr_a, int size_a, int *arr_b, int size_b);

// ############# PUSH_SWAP ############# //
t_stack				*push(t_stack **stack, int value, int i);
t_stack				*create_stack(void);
int					check_sorted(int arr[], int n);
void				push_swap(int arr[], int n);

// ############# ALGO. ############# //
void				radix_sort(int arr[], int n);

#endif