/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ffive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 07:25:47 by omansour          #+#    #+#             */
/*   Updated: 2023/02/11 08:17:26 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_index(t_list **lst)
{
	int		index;
	int		min;
	int		i;
	t_list	*curr;

	curr = *lst;
	min = curr->nb;
	index = 0;
	i = 0;
	while (curr)
	{
		if (curr->nb < min)
		{
			index = i;
			min = curr->nb;
		}
		i++;
		curr = curr->next;
	}
	return (index);
}

void	sort_four(t_list **lst_a, t_list **lst_b)
{
	while (min_index(lst_a))
	{
		if (min_index(lst_a) < 2)
			ra(lst_a);
		else
			rra(lst_a);
	}
	pb(lst_a, lst_b);
}

void	sort_five(t_list **lst_a, t_list **lst_b)
{
	while (min_index(lst_a))
	{
		if (min_index(lst_a) < 3)
			ra(lst_a);
		else
			rra(lst_a);
	}
	pb(lst_a, lst_b);
	while (min_index(lst_a))
	{
		if (min_index(lst_a) < 3)
			ra(lst_a);
		else
			rra(lst_a);
	}
	pb(lst_a, lst_b);
}

void	sort_ffive(t_list **lst_a, t_list **lst_b)
{
	if (ft_lstsize(*lst_a) == 4)
		sort_four(lst_a, lst_b);
	else
		sort_five(lst_a, lst_b);
	set_rank(lst_a);
	sort_three(lst_a);
	while (*lst_b)
		pa(lst_a, lst_b);
	set_rank(lst_a);
}
