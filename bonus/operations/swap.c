/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 06:21:37 by omansour          #+#    #+#             */
/*   Updated: 2023/02/15 23:32:06 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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
}

void	sb(t_list **lst)
{
	do_swap(lst);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	do_swap(lst_a);
	do_swap(lst_b);
}
