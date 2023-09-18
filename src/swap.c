/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:50:27 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/20 07:35:47 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

t_stack *push(t_stack **stack, int value, int i)
{
	t_stack *new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
	{
		message(ERROR_ALLOC);
		return NULL;
	}

	new->value = value;
	new->index = i;
	new->pos = 0;
	new->target_pos = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;

	if (*stack != NULL)
	{
		new->next = *stack;
	}

	*stack = new;
	return new;
}

t_stack	*create_stack(void)
{
	return (NULL);
}

int	check_sorted(int arr[], int n)
{
	int i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}