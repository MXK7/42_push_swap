/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:50:27 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/16 00:38:04 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./../push_swap.h"

t_stack	*push(t_stack **stack, int value, int i)
{
	t_stack *new = (t_stack *)malloc(sizeof(t_stack));
	new->value = value;
	new->index = i;
	new->pos = 0;
	new->target_pos = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = stack;
	stack = new;
}
