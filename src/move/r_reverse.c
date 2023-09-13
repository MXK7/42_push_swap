/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_reverse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 02:13:22 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/13 02:14:30 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../push_swap.h"

void	rra(t_data *stack_a)
{
	int	i;
	int	tmp;

	i = stack_a->a - 1;
	tmp = stack_a->tab[i];
	while (i >= 0)
	{
		stack_a->tab[i + 1] = stack_a->tab[i];
		i--;
	}
	stack_a->tab[0] = tmp;
    ft_printf("rra\n");
}

void	rrb(t_data *stack_b)
{
	int	i;
	int	tmp;

	i = stack_b->a - 1;
	tmp = stack_b->tab[i];
	while (i >= 0)
	{
		stack_b->tab[i + 1] = stack_b->tab[i];
		i--;
	}
	stack_b->tab[0] = tmp;
    ft_printf("rrb\n");
}