/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 07:25:50 by omansour          #+#    #+#             */
/*   Updated: 2023/02/11 07:29:47 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list **lst)
{
	if ((*lst)->rank == 2 && (*lst)->next->rank == 1)
		sa(lst);
	else if ((*lst)->rank == 3 && (*lst)->next->rank == 1)
		ra(lst);
	else if ((*lst)->rank == 2 && (*lst)->next->rank == 3)
		rra(lst);
	else if ((*lst)->rank == 1 && (*lst)->next->rank == 3)
	{
		sa(lst);
		ra(lst);
	}
	else if ((*lst)->rank == 3 && (*lst)->next->rank == 2)
	{
		sa(lst);
		rra(lst);
	}
}
