/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:50:29 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/20 07:32:43 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

static void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

// Fonction d'échange d'éléments dans un tableau
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Fonction de partition pour quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

// Fonction de tri rapide (quicksort) pour trier un tableau
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

void	push_swap(int arr[], int n)
{
	int		i;
	t_stack	*stack;
	// int		value;
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
        if (arr[0] > arr[1])
            sa(arr, n); // Effectuer un swap sur la pile A si nécessaire
        if (arr[0] > arr[n - 1])
            ra(arr, n); // Effectuer une rotation vers le haut de la pile A si nécessaire
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
                ra(arr, n);             // Effectuer une rotation vers le haut de la pile A
                push(&stack, arr[0], 0); // Mettre à jour la pile cost_b
            }
        }
        else
        {
            pb(arr, &n, arr, &n);    // Pousser vers la pile B si nécessaire
            push(&stack, arr[0], 0); // Mettre à jour la pile cost_b
        }
    }
	free_stack(stack); // Libérer la mémoire utilisée par la pile
}

int	main(int argc, char *argv[])
{
	int	size;
	int	*arr;
	int	i;

	if (argc < 2)
	{
		message("Usage: ./push_swap <integer_list>");
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
