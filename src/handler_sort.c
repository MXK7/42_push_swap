/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:57:14 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/10 18:49:17 by mpoussie         ###   ########.fr       */
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

// Tant que la pile A n'est pas vide :
//     1. Trouver le plus petit élément de la pile A et son index (parcourez la pile A).
//     2. S'il est en haut de la pile (au sommet), utilisez pa pour le pousser dans la pile B.
//     3. Sinon, s'il est au milieu de la pile, utilisez ra ou rra en fonction de l'index pour amener l'élément en haut, puis utilisez pa pour le pousser dans la pile B.

// Tant que la pile B n'est pas vide, utilisez pb pour ramener les éléments dans la pile A.

// Tant que la pile A n'est pas triée dans l'ordre croissant :
//     4. Si les deux premiers éléments sont dans le bon ordre, utilisez sa pour les échanger.
//     5. Sinon, si le premier élément est plus grand que le deuxième, utilisez ra pour faire une rotation vers le haut.
//     6. Sinon, si le deuxième élément est plus grand que le premier, utilisez pb pour pousser le deuxième élément dans la pile B.

void	ps_sort_5(t_data *stack_a, t_data *stack_b)
{
	int i = 0;
	int res = 0;

	res = stack_a->tab[0]
	while (!stack_a->tab[i])
	{
		if (stack_a->tab[i] < res)
			res = stack_a->tab[i];
		if (i < )
		i++;
	}
}

void	ps_new_calculate(t_data *stack_a, int argc)
{
	int	tmp;

	tmp = (argc - 1) - stack_a->big_integer;
	stack_a->small_integer = stack_a->big_integer + (tmp * 1 / 3);
	stack_a->big_integer = stack_a->big_integer + (tmp * 2 / 3);
	if (stack_a->big_integer > argc - 4)
		stack_a->big_integer = argc - 4;
}

void	ps_sort_a(t_data *stack_a, t_data *stack_b, int argc)
{
	while (stack_b->a < stack_a->big_integer && stack_a->a != 3)
	{
		if (stack_a->tab[0] > stack_a->big_integer)
		{
			ra(stack_a);
			stack_a->count_action++;
		}
		else if (stack_a->tab[0] <= stack_a->big_integer)
		{
			pb(stack_a, stack_b);
			stack_a->count_action++;
			if (stack_b->a > 1 && stack_a->tab[0] <= stack_a->small_integer
				&& stack_a->a != 3)
			{
				rb(stack_b);
				stack_a->count_action++;
			}
		}
	}
	ps_new_calculate(stack_a, argc);
}

void	ps_sort_b(t_data *stack_a, t_data *stack_b)
{
	int	temp;

	while (stack_b->a != 0)
	{
		stack_a->b = 0;
		while (stack_b->tab[stack_a->b] != stack_b->a)
			stack_a->b++;
		temp = stack_b->a;
		while (temp != stack_b->tab[0])
		{
			if (stack_b->tab[0] == temp - 1)
				pa(stack_a, stack_b);
			else if (stack_a->b < (temp / 2))
				rb(stack_b);
			else
				rrb(stack_b);
		}
		if (stack_a->tab[0] == temp - 1)
		{
			pa(stack_a, stack_b);
			sa(stack_a);
		}
		else
			pa(stack_a, stack_b);
	}
}

void	ps_sort_3_last(t_data *stack_a)
{
	if (stack_a->tab[1] < stack_a->tab[0] && stack_a->tab[1]
		< stack_a->tab[2] && stack_a->tab[2] > stack_a->tab[0])
		sa(stack_a);
	else if (stack_a->tab[1] < stack_a->tab[0] && stack_a->tab[1]
		< stack_a->tab[2] && stack_a->tab[0] > stack_a->tab[2])
		ra(stack_a);
	else if (stack_a->tab[1] > stack_a->tab[0] && stack_a->tab[1]
		> stack_a->tab[2] && stack_a->tab[2] < stack_a->tab[0])
		rra(stack_a);
	else if (stack_a->tab[1] < stack_a->tab[0] && stack_a->tab[1]
		> stack_a->tab[2] && stack_a->tab[2] < stack_a->tab[0])
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (stack_a->tab[1] > stack_a->tab[0] && stack_a->tab[1]
		> stack_a->tab[2] && stack_a->tab[2] > stack_a->tab[0])
	{
		rra(stack_a);
		sa(stack_a);
	}
}