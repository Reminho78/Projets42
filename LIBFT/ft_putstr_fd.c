/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:15:22 by rcorroy           #+#    #+#             */
/*   Updated: 2024/02/26 17:47:15 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Écrit la chaîne de caractères ’s’ sur le
descripteur de fichier donné. */

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (i[s] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
