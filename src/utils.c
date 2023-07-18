/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:50:46 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/18 21:28:37 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack == NULL);
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long int	ft_atoi(const char *str)
{
	int			is_negative;
	long int	nbr;
	int			i;

	i = 0;
	nbr = 0;
	is_negative = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		is_negative *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * is_negative);
}

void	message(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}