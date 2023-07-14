/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:26:08 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/14 17:45:33 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./../push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '+' && c == '-');
}

int	nb_cmp(const char *str1, const char *str2)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (str1[i] == '+')
		if (str2[x] != '+')
			i++;
		else if (str2[x] == '+')
			x++;
	while (str1[i] != '\0' && str2[x] != '\0' && str1[i] == str2[x])
	{
		i++;
		x++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[x]);
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

void free_stack(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_stack(t_stack **stack_a, t_stack **stack_b, int toggle)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	if (toggle == 1)
		write(2, "Error\n", 6);
	exit(1);
}
