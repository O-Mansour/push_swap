/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:20:11 by omansour          #+#    #+#             */
/*   Updated: 2023/02/14 00:35:38 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_digit_sign(int c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+' || c == ' ')
		return (1);
	return (0);
}

int	valid_value(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				if (av[i][j - 1] && av[i][j - 1] != ' ')
					return (1);
				if (av[i][j + 1] < '0' || av[i][j + 1] > '9')
					return (1);
			}
		}
	}
	return (0);
}

int	valid_args(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[++i])
	{
		if (!av[i][0])
			return (1);
		j = -1;
		while (av[i][++j])
			if (!is_digit_sign(av[i][j]))
				return (1);
	}
	if (valid_value(av))
		return (1);
	return (0);
}
