/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 04:04:07 by omansour          #+#    #+#             */
/*   Updated: 2023/02/16 21:57:37 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				nb;
	int				rank;
	struct s_list	*next;
}	t_list;

/*---Utils---*/
int		ft_strcmp(char *s1, char *s2);
int		is_sorted(t_list **lst);
void	show_error(void);
int		re_atoi(char *str);
t_list	*lst_new(char *n);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
/*---parsing_args---*/
int		valid_args(char **av);
t_list	**initialize(char **av);
char	**ft_split(char const *s, char c);
/*---get_next_line---*/
char	*get_next_line(int fd);
int		ft_index(char *str);
char	*re_substr(char	*str, int start, int end);
int		ft_strlen(char *s);
char	*re_strjoin(char *s1, char *s2);
char	*ft_line(char **s);
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

#endif