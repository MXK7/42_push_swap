/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 02:13:26 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/13 02:13:58 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../push_swap.h"

void	ra(t_data *stack_a)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack_a->tab[0];
	while (i < stack_a->a - 1)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	stack_a->tab[i] = tmp;
	ft_printf("ra\n");
}

void	rb(t_data *stack_b)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_b->tab[0];
	while (i < stack_b->a - 1)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		i++;
	}
	stack_b->tab[i] = temp;
	ft_printf("rb\n");
}