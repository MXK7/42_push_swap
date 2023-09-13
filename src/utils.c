/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 03:14:51 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/13 16:47:54 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ps_free(t_data *stack_a, t_data *stack_b)
{
	free(stack_a->tab);
	free(stack_b->tab);
}

static int	ps_white_space(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

long	ps_atoi(const char *str)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 1;
	result = 0;
	while (ps_white_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = j * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * j);
}
