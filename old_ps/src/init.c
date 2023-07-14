/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:51:40 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/14 17:47:15 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./../push_swap.h"

t_stack	*fill_stack_values(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	nbr;
	int			i;

	stack_a = NULL;
	nbr = 0;
	i = 1;
	while (i < argc)
	{
		nbr = ft_atoi(argv[1]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			if (i == 1)
				stack_a = stack_new((int)nbr);
			else
				stack_add_bottom(&stack_a, stack_new((int)nbr));
		i++;
	}
	return (stack_a);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
