/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:07:12 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/07/07 11:21:44 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_storage(char *str)
{
	char	*n_str;
	char	*ptr;
	int		l;

	ptr = ft_strchr(str, '\n');
	if (!ptr)
	{
		n_str = NULL;
		return (ft_free(&str));
	}
	else
		l = (ptr - str) + 1;
	if (!str[l])
		return (ft_free(&str));
	n_str = ft_substr(str, l, ft_strl(str) - l);
	ft_free(&str);
	if (!n_str)
		return (NULL);
	return (n_str);
}

char	*n_line(char *str)
{
	char	*line;
	char	*ptr;
	int		l;

	ptr = ft_strchr(str, '\n');
	l = (ptr - str) + 1;
	line = ft_substr(str, 0, l);
	if (!line)
		return (NULL);
	return (line);
}

char	*readbuf(int fd, char *str)
{
	int		x;
	char	*b;

	x = 1;
	b = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!b)
		return (ft_free(&str));
	b[0] = '\0';
	while (x > 0 && !ft_strchr(b, '\n'))
	{
		x = read(fd, b, BUFFER_SIZE);
		if (x > 0)
		{
			b[x] = '\0';
			str = ft_strjoin(str, b);
		}
	}
	free(b);
	if (x == -1)
		return (ft_free(&str));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((str[fd] && !ft_strchr(str[fd], '\n')) || !str[fd])
		str[fd] = readbuf(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = n_line(str[fd]);
	if (!line)
		return (ft_free(&str[fd]));
	str[fd] = clean_storage(str[fd]);
	return (line);
}
