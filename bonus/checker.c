/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:46:28 by omansour          #+#    #+#             */
/*   Updated: 2023/02/16 22:03:25 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_ops(char *line, t_list **lst_a, t_list **lst_b)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(lst_a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(lst_b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(lst_a, lst_b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(lst_a, lst_b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(lst_a, lst_b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(lst_a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(lst_b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(lst_a, lst_b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(lst_a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(lst_b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(lst_a, lst_b);
	else
		show_error();
}

void	check_ops(t_list **lst_a, t_list **lst_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line || !(*line))
			break ;
		do_ops(line, lst_a, lst_b);
		free (line);
	}
}

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
		check_ops(lst_a, lst_b);
		if (is_sorted(lst_a) && *lst_b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return (0);
}
