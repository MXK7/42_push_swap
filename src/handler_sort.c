/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:57:14 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/11 18:09:29 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ps_sort_3(t_data *stack_a, t_data *stack_b)
{
	int	size_b;

	size_b = 0;
	if (stack_a->tab[0] > stack_a->tab[1])
		sa(stack_a);
	else
		ra(stack_a);
	while (stack_b->tab[size_b] > 0)
	{
		pb(stack_a, stack_b);
		size_b++;
	}
}

void ps_sort_5(t_data *stack_a, t_data *stack_b)
{
    int size_a = stack_a->a;
    int size_b = 0;

    while (size_a > 3)
    {
        pb(stack_a, stack_b);
        size_a--;
        size_b++;
    }

    ps_sort_3(stack_a, stack_b); // Trie les trois éléments restants dans la pile A

    while (size_b > 0)
    {
        pa(stack_a, stack_b);
        size_b--;
    }
}

void ps_sort(t_data *stack_a, t_data *stack_b, int size)
{
    int size_b = 0;

    if (size <= 3)
    {
        // Si le nombre d'éléments est petit (<= 3), utilisez votre tri existant
        ps_sort_3(stack_a, stack_b);
        return;
    }
    // Divisez les éléments en deux parties (stack_a et stack_b)
    int middle = size / 2;
    while (size_b < middle)
    {
        pb(stack_a, stack_b);
        size_b++;
    }
    // Triez récursivement les deux parties
    ps_sort(stack_a, stack_b, middle);
    ps_sort(stack_a, stack_b, size - middle);
    // Fusionnez les deux parties triées
    while (size_b > 0)
    {
        pa(stack_a, stack_b);
        size_b--;
    }
}


bool is_sorted(t_data *stack)
{
    int i;

    if (stack->a < 2)
        return true;

    i = 0;
    while (i < stack->a - 1)
    {
        if (stack->tab[i] > stack->tab[i + 1])
            return false;
        i++;
    }

    return true;
}

/*
Tant que la pile A n'est pas vide :
	1. Trouver le plus petit élément de la pile A et son index (parcourez la pile A).
	2. S'il est en haut de la pile (au sommet),
		utilisez pa pour le pousser dans la pile B.
	3. Sinon, s'il est au milieu de la pile,
		utilisez ra ou rra en fonction de l'index pour amener l'élément en haut,
		puis utilisez pa pour le pousser dans la pile B.

Tant que la pile B n'est pas vide,
	utilisez pb pour ramener les éléments dans la pile A.

Tant que la pile A n'est pas triée dans l'ordre croissant :
	4. Si les deux premiers éléments sont dans le bon ordre,
		utilisez sa pour les échanger.
	5. Sinon, si le premier élément est plus grand que le deuxième,
		utilisez ra pour faire une rotation vers le haut.
	6. Sinon, si le deuxième élément est plus grand que le premier,
		utilisez pb pour pousser le deuxième élément dans la pile B.

*/

// void	ps_sort_5(t_data *stack_a, t_data *stack_b)
// {
// 	int	i;
// 	int	res;
// 	int	min_index;
// 	int	x;

// 	i = 0;
// 	res = stack_a->tab[0];
// 	while (!stack_a->tab[i])
// 	{
// 		if (stack_a->tab[i] < res)
// 			res = stack_a->tab[i];
// 		i++;
// 	}
// 	while (!(stack_a->tab[0] <= stack_a->tab[1]
// 			&& stack_a->tab[1] <= stack_a->tab[2]
// 			&& stack_a->tab[2] <= stack_a->tab[3]
// 			&& stack_a->tab[3] <= stack_a->tab[4]))
// 	{
// 		if (stack_a->tab[0] > stack_a->tab[1])
// 			sa(stack_a);
// 		else
// 			ra(stack_a);
// 	}
// 	min_index = 0;
// 	x = 1;
// 	while (x < 5)
// 	{
// 		if (stack_a->tab[x] < stack_a->tab[min_index])
// 			min_index = x;
// 		x++;
// 	}
// 	while (stack_a->a > 0)
// 	{
// 		if (min_index == 0)
// 			pb(stack_a, stack_b);
// 		else if (min_index <= (stack_a->a - 1) / 2)
// 			ra(stack_a);
// 		else
// 			rra(stack_a);
// 		min_index = (min_index - 1 + stack_a->a) % stack_a->a;
// 	}
// 	while (stack_b->a > 0)
// 		pa(stack_a, stack_b);
// }

// void	ps_new_calculate(t_data *stack_a, int argc)
// {
// 	int	tmp;

// 	tmp = (argc - 1) - stack_a->big_integer;
// 	stack_a->small_integer = stack_a->big_integer + (tmp * 1 / 3);
// 	stack_a->big_integer = stack_a->big_integer + (tmp * 2 / 3);
// 	if (stack_a->big_integer > argc - 4)
// 		stack_a->big_integer = argc - 4;
// }

// void	ps_sort_a(t_data *stack_a, t_data *stack_b, int argc)
// {
// 	while (stack_b->a < stack_a->big_integer && stack_a->a != 3)
// 	{
// 		if (stack_a->tab[0] > stack_a->big_integer)
// 		{
// 			ra(stack_a);
// 			stack_a->count_action++;
// 		}
// 		else if (stack_a->tab[0] <= stack_a->big_integer)
// 		{
// 			pb(stack_a, stack_b);
// 			stack_a->count_action++;
// 			if (stack_b->a > 1 && stack_a->tab[0] <= stack_a->small_integer
// 				&& stack_a->a != 3)
// 			{
// 				rb(stack_b);
// 				stack_a->count_action++;
// 			}
// 		}
// 	}
// 	ps_new_calculate(stack_a, argc);
// }

// void	ps_sort_b(t_data *stack_a, t_data *stack_b)
// {
// 	int	temp;

// 	while (stack_b->a != 0)
// 	{
// 		stack_a->b = 0;
// 		while (stack_b->tab[stack_a->b] != stack_b->a)
// 			stack_a->b++;
// 		temp = stack_b->a;
// 		while (temp != stack_b->tab[0])
// 		{
// 			if (stack_b->tab[0] == temp - 1)
// 				pa(stack_a, stack_b);
// 			else if (stack_a->b < (temp / 2))
// 				rb(stack_b);
// 			else
// 				rrb(stack_b);
// 		}
// 		if (stack_a->tab[0] == temp - 1)
// 		{
// 			pa(stack_a, stack_b);
// 			sa(stack_a);
// 		}
// 		else
// 			pa(stack_a, stack_b);
// 	}
// }

// void	ps_sort_3_last(t_data *stack_a)
// {
// 	if (stack_a->tab[1] < stack_a->tab[0] && stack_a->tab[1] < stack_a->tab[2]
// 		&& stack_a->tab[2] > stack_a->tab[0])
// 		sa(stack_a);
// 	else if (stack_a->tab[1] < stack_a->tab[0]
// 		&& stack_a->tab[1] < stack_a->tab[2]
// 		&& stack_a->tab[0] > stack_a->tab[2])
// 		ra(stack_a);
// 	else if (stack_a->tab[1] > stack_a->tab[0]
// 		&& stack_a->tab[1] > stack_a->tab[2]
// 		&& stack_a->tab[2] < stack_a->tab[0])
// 		rra(stack_a);
// 	else if (stack_a->tab[1] < stack_a->tab[0]
// 		&& stack_a->tab[1] > stack_a->tab[2]
// 		&& stack_a->tab[2] < stack_a->tab[0])
// 	{
// 		ra(stack_a);
// 		sa(stack_a);
// 	}
// 	else if (stack_a->tab[1] > stack_a->tab[0]
// 		&& stack_a->tab[1] > stack_a->tab[2]
// 		&& stack_a->tab[2] > stack_a->tab[0])
// 	{
// 		rra(stack_a);
// 		sa(stack_a);
// 	}
// }