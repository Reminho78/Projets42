/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:43:54 by rcorroy           #+#    #+#             */
/*   Updated: 2024/03/12 20:38:51 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	tab = malloc(len + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len] != '\0')
	{
		tab[i] = s2[len];
		i++;
		len++;
	}
	tab[i] = '\0';
	return (tab);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	s++;
	return ((char *)s);
}

size_t	ft_strlen_until_n(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

char *read_file(int fd)
{
	size_t bytes_readed;
	char *buffer;
	
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL)
		return (NULL);
	bytes_readed = read(fd, buffer, (sizeof(char) * BUFFER_SIZE));

	return (buffer);
	free(buffer);
	buffer = NULL;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i != n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// doit dupliquer src dans dest jusqu'au caractère \n
char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(src);
	dest = (char *)malloc(size * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	ft_memcpy(dest, src, size);
	dest[size] = '\0';
	return (dest);
}