/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:45:10 by omansour          #+#    #+#             */
/*   Updated: 2023/02/14 01:53:10 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	double_free(char **p)
{
	int	i;

	i = -1;
	while (p[++i])
		free(p[i]);
	free(p);
}

void	final_check(t_list *lst, int new)
{
	while (lst)
	{
		if (lst->nb == new)
			show_error();
		lst = lst->next;
	}
}

t_list	*get_max(t_list **lst)
{
	t_list	*max;
	t_list	*curr;

	curr = *lst;
	max = *lst;
	while (curr && max->rank)
	{
		if (!(curr->rank))
		{
			max = curr;
			break ;
		}
		curr = curr->next;
	}
	while (curr)
	{
		if (curr->nb > max->nb && !(curr->rank))
			max = curr;
		curr = curr->next;
	}
	return (max);
}

void	set_rank(t_list **lst_a)
{
	int		size;
	t_list	*max;
	t_list	*curr;

	curr = *lst_a;
	while (curr)
	{
		curr->rank = 0;
		curr = curr->next;
	}
	size = ft_lstsize(*lst_a);
	while (size)
	{
		max = get_max(lst_a);
		max->rank = size;
		size--;
	}
}

t_list	**initialize(char **av)
{
	t_list	**lst_a;
	char	**splited;
	int		i;
	int		j;

	i = 0;
	lst_a = malloc(sizeof(t_list *));
	if (!lst_a)
		return (NULL);
	*lst_a = NULL;
	while (av[++i])
	{
		splited = ft_split(av[i], ' ');
		if (!splited)
			return (NULL);
		j = -1;
		while (splited[++j])
		{
			final_check(*lst_a, re_atoi(splited[j]));
			ft_lstadd_back(lst_a, lst_new(splited[j]));
		}
		double_free(splited);
	}
	set_rank(lst_a);
	return (lst_a);
}
