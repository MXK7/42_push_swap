/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 02:13:01 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/13 16:54:30 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../push_swap.h"

void	pb(t_data *stack_a, t_data *stack_b)
{
	int	i;
	int	x;

	i = stack_b->a + 1;
	while (i > 0)
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
		i--;
	}
	stack_b->tab[0] = stack_a->tab[0];
	x = 0;
	while (x < stack_a->a)
	{
		stack_a->tab[x] = stack_a->tab[x + 1];
		x++;
	}
	stack_a->a--;
	stack_b->a++;
	ft_printf("pb\n");
}

void	pa(t_data *stack_a, t_data *stack_b)
{
	int	i;
	int	x;

	i = stack_a->a + 1;
	while (i > 0)
	{
		stack_a->tab[i] = stack_a->tab[i - 1];
		i--;
	}
	stack_a->tab[0] = stack_b->tab[0];
	x = 0;
	while (x < stack_b->a)
	{
		stack_b->tab[x] = stack_b->tab[x + 1];
		x++;
	}
	stack_a->a++;
	stack_b->a--;
	ft_printf("pa\n");
}
