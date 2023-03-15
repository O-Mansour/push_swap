/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 06:21:35 by omansour          #+#    #+#             */
/*   Updated: 2023/02/15 23:28:16 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	do_rrotate(t_list **lst)
{
	t_list	*before_last;
	t_list	*last;

	if (!lst || ft_lstsize(*lst) < 2)
		return ;
	before_last = *lst;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	ft_lstadd_front(lst, last);
}

void	rra(t_list **lst)
{
	do_rrotate(lst);
}

void	rrb(t_list **lst)
{
	do_rrotate(lst);
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	do_rrotate(lst_a);
	do_rrotate(lst_b);
}
