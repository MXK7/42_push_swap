/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:36:24 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/14 17:46:44 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./../push_swap.h"

static int	args_nbr(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] && is_digit(str[i]))
		i++;
	if (str[i] != '\0' && !is_digit(str[i]))
		return (0);
	return (1);
}

static int	args_zero(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]))
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

static	have_duplicates(char **str)
{
	int	i;
	int	x;

	i = 1;
	while (str[i])
	{
		x = 1;
		while (str[x])
		{
			if (x != i && nb_cmp(str[i], str[x]) == 0)
				return (1);
			x++;
		}
	}
	return (0);
}

int	is_correct_imput(char **str)
{
	int	i;
	int	nb_zero;

	i = 1;
	nb_zero = 0;
	while (str[i])
	{
		if (args_nbr(str[i]))
			return (0);
		nb_zero += args_zero(str[i]);
		i++;
	}
	if (nb_zero > 1)
		return (0);
	if (have_duplicates(str))
		return (0);
	return (1);
}
