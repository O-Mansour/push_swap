/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:32:18 by omansour          #+#    #+#             */
/*   Updated: 2023/02/14 00:35:54 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_list	**lst_a;
	t_list	**lst_b;

	if (ac > 1)
	{
		if (valid_args(av))
			show_error();
		lst_b = malloc(sizeof(t_list *));
		if (!lst_b)
			show_error();
		*lst_b = NULL;
		lst_a = initialize(av);
		if (!lst_a)
			show_error();
		if (is_sorted(lst_a))
			return (0);
		if (ft_lstsize(*lst_a) == 2)
			sa(lst_a);
		else if (ft_lstsize(*lst_a) == 3)
			sort_three(lst_a);
		else if (ft_lstsize(*lst_a) <= 5)
			sort_ffive(lst_a, lst_b);
		else
			sort_x(lst_a, lst_b);
	}
}
