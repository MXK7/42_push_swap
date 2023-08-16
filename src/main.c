/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:50:29 by mpoussie          #+#    #+#             */
/*   Updated: 2023/08/16 21:53:17 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	push_swap(int arr[], int n)
{
	int		i;
	t_stack	*stack;
	int		value;
	int		top_value;

	i = 0;
	stack = create_stack();
	while (i < n)
	{
		push(&stack, arr[i], i);
		i++;
	}
	while (!is_empty(stack))
	{
		value = pop(&stack);
		if (value % 2 == 0)
			ra(arr, n); // Rotation vers le haut de la pile A
		else
			pb(arr, &n, arr, &n); // Pousser vers la pile B
		if (value < 10)
			sa(arr, n); // Swap A
		else
			rb(arr, n); // Rotation vers le haut de la pile B
	}
	while (!check_sorted(arr, n))
	{
		// Effectuer d'autres mouvements et opérations pour trier les piles
		// en utilisant les mouvements disponibles (ra, pb, sa, rb, etc.)
		// Exemple :
		if (arr[0] > arr[1])
			sa(arr, n); // Effectuer un swap sur la pile A si nécessaire
		if (arr[0] > arr[n - 1])
			ra(arr, n);
		// Effectuer une rotation vers le haut de la pile A si nécessaire
		if (!is_empty(stack))
		{
			top_value = stack->value;
			if (arr[0] > top_value)
			{
				pb(arr, &n, arr, &n);    // Pousser vers la pile B si nécessaire
				push(&stack, arr[0], 0); // Mettre à jour la pile cost_b
			}
			else
			{
				ra(arr, n);
				// Effectuer une rotation vers le haut de la pile A
				push(&stack, arr[0], 0); // Mettre à jour la pile cost_b
			}
		}
		else
		{
			pb(arr, &n, arr, &n);    // Pousser vers la pile B si nécessaire
			push(&stack, arr[0], 0); // Mettre à jour la pile cost_b
		}
	}
	while (!is_empty(stack))
		pop(&stack);
}

int	main(int argc, char *argv[])
{
	int	size;
	int	*arr;
	int	i;

	if (argc < 2)
	{
		ft_printf("Usage: ./push_swap <integer_list>\n");
		return (1);
	}
	size = argc - 1;
	arr = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	push_swap(arr, size);
	free(arr);
	return (0);
}
