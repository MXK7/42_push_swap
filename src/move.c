/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:31:51 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/10 16:42:28 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void sa(t_data *stack_a)
{
    int temp;

    temp = stack_a->tab[0];
    stack_a->tab[0] = stack_a->tab[1];
    stack_a->tab[1] = temp;
    ft_printf("sa\n");
}

void	ra(t_data *stack_a)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_a->tab[0];
	while (i < stack_a->a - 1)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	stack_a->tab[i] = temp;
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

void pb(t_data *stack_a, t_data *stack_b)
{
    int i;
    int x;
    
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
    ft_printf("pb\n");
}

void pa(t_data *stack_a, t_data *stack_b)
{
    int i;
    int x;
    
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
    ft_printf("pa\n");
}

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
