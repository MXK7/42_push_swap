/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:49:58 by mpoussie          #+#    #+#             */
/*   Updated: 2023/08/16 21:55:28 by mpoussie         ###   ########.fr       */
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

// ############# CORE ############# //

// ############# ROTATE ############# //

// ############# ALGO. ############# //

#endif