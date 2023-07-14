/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:50:27 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/14 19:46:13 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./../push_swap.h"

int pop(t_stack **stack)
{
    if (*stack == NULL)
    {
        printf("La pile est vide.\n");
        return -1;
    }

    int value = (*stack)->value;
    t_stack *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return value;
}

int is_empty(t_stack *stack)
{
    return stack == NULL;
}