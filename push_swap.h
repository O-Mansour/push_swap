/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:32:23 by omansour          #+#    #+#             */
/*   Updated: 2023/02/16 21:45:49 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				nb;
	int				rank;
	struct s_list	*next;
}	t_list;

/*---Utils---*/
void	show_error(void);
int		re_atoi(char *str);
t_list	*lst_new(char *n);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
/*---parsing_args---*/
int		valid_args(char **av);
t_list	**initialize(char **av);
char	**ft_split(char const *s, char c);
void	set_rank(t_list **lst_a);
/*---Operations---*/
void	sa(t_list **lst);
void	sb(t_list **lst);
void	ss(t_list **lst_a, t_list **lst_b);
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_a, t_list **lst_b);
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **lst_a, t_list **lst_b);
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **lst_a, t_list **lst_b);
/*---For_sorting---*/
int		is_sorted(t_list **lst);
void	sort_three(t_list **lst);
void	sort_ffive(t_list **lst_a, t_list **lst_b);
void	sort_x(t_list **lst_a, t_list **lst_b);

#endif