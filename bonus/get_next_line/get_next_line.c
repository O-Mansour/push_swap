/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:02:46 by omansour          #+#    #+#             */
/*   Updated: 2023/02/16 21:58:25 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

char	*to_free(char **str, char *cpy)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	free(cpy);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*cpy;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cpy = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!cpy)
		return (NULL);
	n = 1;
	while (n > 0 && ft_index(str) == -1)
	{
		n = read(fd, cpy, BUFFER_SIZE);
		if (n == -1)
			return (to_free(&str, cpy));
		cpy[n] = '\0';
		str = re_strjoin(str, cpy);
	}
	free (cpy);
	return (ft_line(&str));
}
