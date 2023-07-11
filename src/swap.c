/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:23:20 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/09 01:57:24 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void swap(t_stack *stack)
{
    int tmp;

    if (stack == NULL || stack->next == NULL)
        return ;
    tmp = stack->value;
    stack->value = stack->next->value;
    stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
