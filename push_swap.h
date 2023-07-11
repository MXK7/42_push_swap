/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:49:58 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/09 02:08:17 by mpoussie         ###   ########.fr       */
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
int					is_digit(char c);
int					is_sign(char c);
int					nb_cmp(const char *str1, const char *str2);
void				exit_stack(t_stack **stack_a, t_stack **stack_b, int toggle);
void				free_stack(t_stack **stack);
long int			ft_atoi(const char *str);

// ############# CORE ############# //
t_stack				*stack_new(int value);
void				stack_add_bottom(t_stack **stack, t_stack *new);
t_stack				*get_stack_bottom(t_stack *stack);
int					get_stack_size(t_stack *stack);

// ############# INIT ############# //
void				assign_index(t_stack *stack_a, int ac);
t_stack				*fill_stack_values(int ac, char **av);

// ############# INSTRU. FCT. ############# //
// TODO

// ############# ALGO. ############# //
// TODO

#endif