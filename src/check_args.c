/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 03:09:02 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/05 09:12:00 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

static int	ps_check_sort(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	ps_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 3)
		return (0);
	if (ps_check_sort(argc, argv))
		return (1);
	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i])
				|| ft_isdigit(ft_atoi(argv[j])) || ft_atoi(argv[j]) < INT_MIN
				|| ft_atoi(argv[j]) > INT_MAX || ft_atoi(argv[1]) < INT_MIN
				|| ft_atoi(argv[1]) > INT_MAX)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
