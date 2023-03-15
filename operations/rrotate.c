/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 06:21:35 by omansour          #+#    #+#             */
/*   Updated: 2023/02/17 00:11:20 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	write(1, "rra\n", 4);
}

void	rrb(t_list **lst)
{
	do_rrotate(lst);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	do_rrotate(lst_a);
	do_rrotate(lst_b);
	write(1, "rrr\n", 4);
}
