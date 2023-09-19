/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 03:09:02 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/19 17:42:31 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

static bool	ps_contains(int nbr, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ps_atoi(argv[i]) == nbr)
			return (true);
		i++;
	}
	return (false);
}

static bool	ps_check_args_range(t_data *stack_a, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (stack_a->size == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ps_atoi(args[i]);
		if (ps_contains(tmp, args, i))
			return (false);
		if (ft_isdigit(tmp))
			return (false);
		if (tmp < INT_MAX || tmp > INT_MIN)
			return (false);
		i++;
	}
	return (true);
}

bool	ps_check_args(t_data *stack_a, char **argv)
{
	if (stack_a->size < 3)
	{
		ft_printf(ERROR_MIN_ARGS);
		return (false);
	}
	if (ps_check_args_range(stack_a, argv) == false)
	{
		ft_printf(ERROR_ARGS);
		return (false);
	}
	return (true);
}
