/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 03:09:02 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/13 02:46:48 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

static int	ps_check_sort(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ps_atoi(argv[i]) > ps_atoi(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

static int ps_neg_nbr(char *str)
{
	return ((*str == '-') - (*str >= 48 && *str <= 57));
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
			if (ps_atoi(argv[j]) == ps_atoi(argv[i]) || !ps_neg_nbr(argv[j]) || !ps_neg_nbr(argv[1])
				|| ps_atoi(argv[j]) < INT_MIN || ps_atoi(argv[j]) > INT_MAX
				|| ps_atoi(argv[1]) < INT_MIN || ps_atoi(argv[1]) > INT_MAX)
				{
					return (ft_printf(ERROR_ARGS));
					return (1);
				}
			j++;
		}
		i++;
	}
	return (0);
}
