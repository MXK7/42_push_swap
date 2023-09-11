/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:49:58 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/11 18:09:55 by mpoussie         ###   ########.fr       */
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
	int	c;
	int	big_integer;
	int	small_integer;
	int	count_action;
	int	*tab;
}		t_data;

// ############# UTILS ############# //
void	ps_free(char **str);

// ############# CORE ############# //
int		ps_check_args(int argc, char **argv);
void	ps_init_nbr(t_data *stack, int argc);
void	ps_init_index(t_data *stack, int argc, int *storage);

// ############# ACTIONS ############# //
void	sa(t_data *stack_a);
void	ra(t_data *stack_a);
void	rb(t_data *stack_a);
void	pa(t_data *stack_a, t_data *stack_b);
void	pb(t_data *stack_a, t_data *stack_b);
void	rra(t_data *stack_a);
void	rrb(t_data *stack_b);

// ############# ALGO. ############# //
bool	is_sorted(t_data *stack);
void	ps_sort_3(t_data *stack_a, t_data *stack_b);
void	ps_sort_5(t_data *stack_a, t_data *stack_b);
void	ps_sort(t_data *stack_a, t_data *stack_b, int size);

#endif