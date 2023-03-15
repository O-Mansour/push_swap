/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 06:21:29 by omansour          #+#    #+#             */
/*   Updated: 2023/02/15 23:45:25 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (!lst_b || !(*lst_b) || !lst_a)
		return ;
	tmp = *lst_b;
	*lst_b = (*lst_b)->next;
	tmp->next = NULL;
	ft_lstadd_front(lst_a, tmp);
}

void	pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (!lst_a || !(*lst_a) || !lst_b)
		return ;
	tmp = *lst_a;
	*lst_a = (*lst_a)->next;
	tmp->next = NULL;
	ft_lstadd_front(lst_b, tmp);
}
