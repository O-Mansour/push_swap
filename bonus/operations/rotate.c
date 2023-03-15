/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 06:21:32 by omansour          #+#    #+#             */
/*   Updated: 2023/02/15 23:26:45 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	do_rotate(t_list **lst)
{
	t_list	*tmp;

	if (!lst || ft_lstsize(*lst) < 2)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
}

void	ra(t_list **lst)
{
	do_rotate(lst);
}

void	rb(t_list **lst)
{
	do_rotate(lst);
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	do_rotate(lst_a);
	do_rotate(lst_b);
}
