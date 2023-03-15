/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 07:25:53 by omansour          #+#    #+#             */
/*   Updated: 2023/02/16 20:39:03 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index(t_list *lst, int start, int end)
{
	int	index;

	index = 0;
	while (lst)
	{
		if (lst->rank >= start && lst->rank <= end)
			return (index);
		lst = lst->next;
		index++;
	}
	return (-1);
}

void	to_lst_b(t_list **lst_a, t_list **lst_b, int start, int end)
{
	while (get_index(*lst_a, start, end) != -1)
	{
		if ((*lst_a)->rank >= start && (*lst_a)->rank <= end)
		{
			pb(lst_a, lst_b);
			if ((*lst_b)->rank <= (start + end) / 2)
			{
				if (*lst_a && ((*lst_a)->rank > end || (*lst_a)->rank < start))
					rr(lst_a, lst_b);
				else
					rb(lst_b);
			}
		}
		else
			ra(lst_a);
	}
}

void	max_to_a(t_list **lst_a, t_list **lst_b, int size)
{
	while ((*lst_b)->rank != size)
		rb(lst_b);
	pa(lst_a, lst_b);
}

void	to_lst_a(t_list **lst_a, t_list **lst_b, int size)
{
	while (*lst_b || !is_sorted(lst_a))
	{
		if (*lst_b && (*lst_b)->rank + 1 == (*lst_a)->rank)
			pa(lst_a, lst_b);
		else if (*lst_b && ((*lst_b)->rank > ft_lstlast(*lst_a)->rank
				|| ft_lstlast(*lst_a)->rank == size))
		{
			pa(lst_a, lst_b);
			if (get_index(*lst_b, (*lst_a)->rank - 1,
					(*lst_a)->rank - 1) < ft_lstsize(*lst_b) / 2)
				rr(lst_a, lst_b);
			else
				ra(lst_a);
		}
		else if ((*lst_a)->rank == ft_lstlast(*lst_a)->rank + 1)
			rra(lst_a);
		else if (ft_lstsize(*lst_b) > 1)
		{
			if (get_index(*lst_b, (*lst_a)->rank - 1,
					(*lst_a)->rank - 1) < ft_lstsize(*lst_b) / 2)
				rb(lst_b);
			else
				rrb(lst_b);
		}
	}
}

void	sort_x(t_list **lst_a, t_list **lst_b)
{
	int	i;
	int	size;

	i = 25;
	size = ft_lstsize(*lst_a);
	while (*lst_a)
	{
		to_lst_b(lst_a, lst_b, (size / 2) - i, (size / 2) + i);
		i += 25;
	}
	max_to_a(lst_a, lst_b, size);
	to_lst_a(lst_a, lst_b, size);
}
