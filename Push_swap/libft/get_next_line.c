/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:19:45 by rcorroy           #+#    #+#             */
/*   Updated: 2024/04/18 18:47:44 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	maj_store(char **store, char *rest)
{
	char	*new_store;

	if (*(rest + 1) != '\0')
	{
		new_store = ft_strdup(rest + 1);
		free(*store);
		*store = new_store;
	}
	else
	{
		free(*store);
		*store = NULL;
	}
}

char	*get_line(char **store)
{
	char	*rest;
	char	*line;
	size_t	len;

	rest = ft_strchr(*store, '\n');
	if (!rest)
	{
		len = ft_strlen(*store);
		line = malloc(len + 1);
		if (!line)
			return (NULL);
		ft_strlcpy(line, *store, len + 1);
		free(*store);
		*store = NULL;
	}
	else
	{
		len = rest - *store + 1;
		line = malloc(len + 1);
		if (!line)
			return (NULL);
		ft_strlcpy(line, *store, len + 1);
		maj_store(store, rest);
	}
	return (line);
}

static void	read_and_store(int fd, char **store)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	int		bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (!*store)
			*store = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(*store, buf);
			free(*store);
			*store = temp;
		}
		if (ft_strchr(*store, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes_read == -1 && *store)
	{
		free(*store);
		*store = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*store = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_and_store(fd, &store);
	if (!store || *store == '\0')
	{
		if (store)
		{
			free(store);
			store = NULL;
		}
		return (NULL);
	}
	return (get_line(&store));
}