/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:49:58 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/13 02:24:57 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define STACK_SIZE 100
# define ERROR_ALLOC "A memory allocation error has occurred."
# define EMPTY_STACK "The stack is empty."
# define STACK_IS_EMPTY "The stack is now empty."
# define ERROR_ARGS "The args is not numbers."

typedef struct s_data
{
	int	a;
	int	b;
	int size;
	int	big_integer;
	int	small_integer;
	int	count_action;
	int	*tab;
}		t_data;

// ############# UTILS ############# //
void	ps_free(t_data *stack_a, t_data *stack_b);
long	ps_atoi(const char *str);

// ############# CORE ############# //
int		ps_check_args(int argc, char **argv);
void	ps_init_nbr(t_data *stack, int argc);
void	ps_init_index(t_data *stack, int argc, int *storage);

// ############# ACTIONS ############# //
void	sa(t_data *stack_a);
void	sb(t_data *stack_a);
void	ra(t_data *stack_a);
void	rb(t_data *stack_a);
void	pa(t_data *stack_a, t_data *stack_b);
void	pb(t_data *stack_a, t_data *stack_b);
void	rra(t_data *stack_a);
void	rrb(t_data *stack_b);

// ############# ALGO. ############# //
void	ps_sort_3(t_data *stack_a);
void	ps_sort_5(t_data *stack_a, t_data *stack_b);
void 	ps_find_median(t_data *stack_a);
void 	ps_sort_a(t_data *stack_a, t_data *stack_b);
void	ps_sort_b(t_data *stack_a, t_data *stack_b);

#endif