/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:02:38 by omansour          #+#    #+#             */
/*   Updated: 2023/02/16 21:58:38 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_index(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*re_substr(char	*str, int start, int end)
{
	char	*new;
	int		i;

	if (start > end)
		return (NULL);
	new = malloc(sizeof(char) * (end - start + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (start <= end)
		new[i++] = str[start++];
	new[i] = '\0';
	return (new);
}

char	*re_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	while (*s2)
		new[i++] = *s2++;
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*ft_line(char **s)
{
	char	*new;
	char	*tmp;
	int		i;

	if (!*s)
		return (NULL);
	i = ft_index(*s);
	if (i < 0)
	{
		new = re_substr(*s, 0, ft_strlen(*s) - 1);
		free (*s);
		*s = NULL;
		return (new);
	}
	new = re_substr(*s, 0, i);
	tmp = re_substr(*s, i + 1, ft_strlen(*s) - 1);
	free(*s);
	*s = tmp;
	return (new);
}
