/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:50:29 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/19 17:10:46 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

static void	init_data(t_data *stack, t_data *stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a->size - 1)
	{
		stack->tab[i] = -1;
		i++;
	}
	stack->a = 0;
	stack->count_action = 0;
	stack->big_integer = (stack_a->size - 1) * 2 / 3;
	stack->small_integer = (stack_a->size - 1) / 3;
}

static int	init_stack(t_data *stack_a, t_data *stack_b)
{
	stack_a->tab = malloc(sizeof(int) * (stack_a->size));
	if (!stack_a->tab)
		return (1);
	stack_b->tab = malloc(sizeof(int) * (stack_a->size));
	if (!stack_b->tab)
		return (1);
	init_data(stack_a, stack_a);
	init_data(stack_b, stack_a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	stack_a;
	t_data	stack_b;

	stack_a.size = argc;
	if (ps_check_args(&stack_a, argv) != true)
		return (0);
	if (init_stack(&stack_a, &stack_b))
		return (ft_printf(ERROR_ALLOC));
	while (stack_a.a < stack_a.size - 1)
	{
		stack_a.tab[stack_a.a] = ps_atoi(argv[stack_a.a + 1]);
		stack_a.a++;
	}
	ps_init_nbr(&stack_a);
	if (argc == 6)
		ps_sort_5(&stack_a, &stack_b);
	while (stack_a.a != 3)
		ps_sort_a(&stack_a, &stack_b);
	ps_sort_3(&stack_a);
	ps_sort_b(&stack_a, &stack_b);
	ps_free(&stack_a, &stack_b);
	return (0);
}
