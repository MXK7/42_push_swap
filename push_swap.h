/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:49:58 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/16 00:45:13 by mpoussie         ###   ########.fr       */
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
int					is_empty(int stack);

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

// ############# INIT ############# //
t_stack				*push(t_stack **stack, int value, int i);
void				push_swap(int arr[], int n);

// ############# INSTRU. FCT. ############# //

// ############# ALGO. ############# //
void				radix_sort(int arr[], int n);

#endif