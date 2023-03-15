/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 06:21:37 by omansour          #+#    #+#             */
/*   Updated: 2023/02/17 00:12:04 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_swap(t_list **lst)
{
	int	n;

	if (!lst || ft_lstsize(*lst) < 2)
		return ;
	n = (*lst)->nb;
	(*lst)->nb = (*lst)->next->nb;
	(*lst)->next->nb = n;
	n = (*lst)->rank;
	(*lst)->rank = (*lst)->next->rank;
	(*lst)->next->rank = n;
}

void	sa(t_list **lst)
{
	do_swap(lst);
	write(1, "sa\n", 3);
}

void	sb(t_list **lst)
{
	do_swap(lst);
	write(1, "sb\n", 3);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	do_swap(lst_a);
	do_swap(lst_b);
	write(1, "ss\n", 3);
}
