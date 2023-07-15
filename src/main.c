/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:50:29 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/16 00:45:56 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	push_swap(int arr[], int n)
{
	int		i;
	t_stack	*stack;
	int	current;
	int		value;

	i = 0;
	radix_sort(arr, n);
	stack->cost_a = 0;
	stack->cost_b = 0; // Initialiser la pile cost_b
	while (i < n)
	{
		push(&stack, arr[i], i);
		i++;
	}
	while (!is_empty(stack->cost_a))
	{
		current = stack->cost_a;
		value = pop(&stack);
		if (stack->value % 2 == 0)
			ra(arr, n); // Rotation vers le haut de la pile A
		else
			pb(arr, &n, arr, &n); // Pousser vers la pile B
		if (stack->value < 10)
			sa(arr, n); // Swap A
		else
			rb(arr, n); // Rotation vers le haut de la pile B
	}
	while (!is_empty(stack->cost_b))
	{
		current = stack->cost_b;
		value = pop(&stack);
		push(&stack, value, stack->index);
		pa(arr, &n, arr, &n); // Pousser vers la pile A
	}
	while (!is_empty(stack->cost_a) && !is_empty(stack->cost_a))
		pop(&stack);
}

int	main(void)
{
	int arr[] = {5, 2, 8, 3, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Avant le tri : ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	push_swap(arr, n);

	printf("Après le tri : ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return (0);
}