/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:43:08 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/18 21:28:46 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	pop(t_stack **stack)
{
	int		value;
	t_stack	*temp;

	if (*stack == NULL)
	{
		message(EMPTY_STACK);
		return (-1);
	}
	value = (*stack)->value;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	if (*stack == NULL)
		message(STACK_IS_EMPTY);
	return (value);
}

/*
	Mouvement : Swap A
	- Échange les deux premiers éléments de la pile A
*/
void	sa(int *arr_a, int size_a)
{
	int	temp;

	if (size_a >= 2)
	{
		temp = arr_a[0];
		arr_a[0] = arr_a[1];
		arr_a[1] = temp;
		message("sa\n");
	}
}

/*
	Mouvement : Swap B
	- Échange les deux premiers éléments de la pile B
*/
void	sb(int *arr_b, int size_b)
{
	int	temp;

	if (size_b >= 2)
	{
		temp = arr_b[0];
		arr_b[0] = arr_b[1];
		arr_b[1] = temp;
		message("sb\n");
	}
}

/*
	Mouvement : Swap A et B
	- Effectue un sa suivi d'un sb
*/
void	ss(int *arr_a, int size_a, int *arr_b, int size_b)
{
	int	temp;
	int	temp2;

	if (size_a >= 2 && size_b >= 2)
	{
		temp = arr_a[0];
		arr_a[0] = arr_a[1];
		arr_a[1] = temp;
		temp2 = arr_b[0];
		arr_b[0] = arr_b[1];
		arr_b[1] = temp2;
		message("ss\n");
	}
}

/*
	Mouvement : Push A
	- Prend le premier élément de la pile B et le place au sommet de la pile A
*/
void	pa(int *arr_a, int *size_a, int *arr_b, int *size_b)
{
	int	i;

	if (*size_b > 0)
	{
		i = *size_a;
		while (i > 0)
		{
			arr_a[i] = arr_a[i - 1];
			i--;
		}
		arr_a[0] = arr_b[0];
		(*size_a)++;
		i = 0;
		while (i < *size_b - 1)
		{
			arr_b[i] = arr_b[i + 1];
			i++;
		}
		(*size_b)--;
		message("pa\n");
	}
}

/*
	Mouvement : Push B
	- Prend le premier élément de la pile A et le place au sommet de la pile B
*/
void	pb(int *arr_a, int *size_a, int *arr_b, int *size_b)
{
	int	i;

	if (*size_a > 0)
	{
		for (i = *size_b; i > 0; i--)
		{
			arr_b[i] = arr_b[i - 1];
		}
		arr_b[0] = arr_a[0];
		(*size_b)++;
		for (i = 0; i < *size_a - 1; i++)
		{
			arr_a[i] = arr_a[i + 1];
		}
		(*size_a)--;
		message("pb\n");
	}
}

/*
	Mouvement : Rotate A
	- Décale tous les éléments de la pile A vers le haut,
		le premier élément devient le dernier
*/
void	ra(int *arr_a, int size_a)
{
	int	temp;
	int	i;

	if (size_a >= 2)
	{
		temp = arr_a[0];
		i = 0;
		while (i < size_a - 1)
		{
			arr_a[i] = arr_a[i + 1];
			i++;
		}
		arr_a[size_a - 1] = temp;
		message("ra\n");
	}
}

/*
	Mouvement : Rotate B
	- Décale tous les éléments de la pile B vers le haut,
		le premier élément devient le dernier
*/
void	rb(int *arr_b, int size_b)
{
	int	temp;
	int	i;

	if (size_b >= 2)
	{
		temp = arr_b[0];
		i = 0;
		while (i < size_b - 1)
		{
			arr_b[i] = arr_b[i + 1];
			i++;
		}
		arr_b[size_b - 1] = temp;
		message("rb\n");
	}
}

/*
	Mouvement : Rotate A et B
	- Effectue un ra suivi d'un rb
*/
void	rr(int *arr_a, int size_a, int *arr_b, int size_b)
{
	int	temp;
	int	i;
	int	temp2;
	int	i2;

	if (size_a >= 2 && size_b >= 2)
	{
		temp = arr_a[0];
		i = 0;
		while (i < size_a - 1)
		{
			arr_a[i] = arr_a[i + 1];
			i++;
		}
		arr_a[size_a - 1] = temp;
		temp2 = arr_b[0];
		i2 = 0;
		while (i2 < size_b - 1)
		{
			arr_b[i2] = arr_b[i2 + 1];
			i2++;
		}
		arr_b[size_b - 1] = temp2;
		message("rr\n");
	}
}

/*
	Mouvement : Reverse Rotate A
	- Décale tous les éléments de la pile A vers le bas,
		le dernier élément devient le premier
*/
void	rra(int *arr_a, int size_a)
{
	int	temp;
	int	i;

	if (size_a >= 2)
	{
		temp = arr_a[size_a - 1];
		i = size_a - 1;
		while (i > 0)
		{
			arr_a[i] = arr_a[i - 1];
			i--;
		}
		arr_a[0] = temp;
		message("rra\n");
	}
}

/*
	Mouvement : Reverse Rotate B
	- Décale tous les éléments de la pile B vers le bas,
		le dernier élément devient le premier
*/
void	rrb(int *arr_b, int size_b)
{
	int	temp;
	int	i;

	if (size_b >= 2)
	{
		temp = arr_b[size_b - 1];
		i = size_b - 1;
		while (i > 0)
		{
			arr_b[i] = arr_b[i - 1];
			i--;
		}
		arr_b[0] = temp;
		message("rrb\n");
	}
}

/*
	Mouvement : Reverse Rotate A et B - Effectue un rra suivi d'un rrb
*/
void	rrr(int *arr_a, int size_a, int *arr_b, int size_b)
{
	int	temp;
	int	i;
	int	temp2;
	int	i2;

	if (size_a >= 2 && size_b >= 2)
	{
		temp = arr_a[size_a - 1];
		i = size_a - 1;
		while (i > 0)
		{
			arr_a[i] = arr_a[i - 1];
			i--;
		}
		arr_a[0] = temp;
		temp2 = arr_b[size_b - 1];
		i2 = size_b - 1;
		while (i2 > 0)
		{
			arr_b[i2] = arr_b[i2 - 1];
			i2--;
		}
		arr_b[0] = temp2;
		message("rrr\n");
	}
}
