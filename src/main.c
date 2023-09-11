/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:50:29 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/11 17:40:29 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

// void	ps_print(t_data *stack, char **argv)
// {
//     for (int i = 0; i != stack->a; i++)
// 	{
//         ft_printf("Element %d : %d\n", i, argv[stack->tab[i]]);
//     }
// }

static void	init_data(t_data *stack, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		stack->tab[i] = -1;
		i++;
	}
	stack->a = 0;
	stack->count_action = 0;
	stack->big_integer = (argc - 1) * 2 / 3;
	stack->small_integer = (argc - 1) / 3;
}

static int	init_stack(t_data *stack_a, t_data *stack_b, int argc)
{
	stack_a->tab = malloc(sizeof(int) * (argc - 1));
	if (!stack_a->tab)
		return (1);
	stack_b->tab = malloc(sizeof(int) * (argc - 1));
	if (!stack_b->tab)
		return (1);
	init_data(stack_a, argc);
	init_data(stack_b, argc);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	stack_a;
	t_data	stack_b;

	if (ps_check_args(argc, argv))
		return (ft_printf(ERROR_ARGS));
	if (init_stack(&stack_a, &stack_b, argc))
		return (ft_printf(ERROR_ALLOC));
	while (stack_a.a < argc - 1)
	{
		stack_a.tab[stack_a.a] = ft_atoi(argv[stack_a.a + 1]);
		stack_a.a++;
	}
	ps_init_nbr(&stack_a, argc);
	if (argc == 6)
	{
		ps_sort_5(&stack_a, &stack_b);
		return (0);
	}
	else if (argc == 4)
	{
		ps_sort_3(&stack_a, &stack_b);
		return (0);
	}
	else
	{
		ps_sort(&stack_a, &stack_b, stack_a.a);
		return(0);
	}
	return (0);
}
