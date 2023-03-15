/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:55:42 by omansour          #+#    #+#             */
/*   Updated: 2023/02/11 13:36:05 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	re_atoi(char *str)
{
	int						i;
	int						sign;
	unsigned long long		res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
		if (res > 2147483648 || (res > INT32_MAX && sign == 1))
			show_error();
	}
	return (res * sign);
}
