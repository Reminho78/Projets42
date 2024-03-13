/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:28:46 by rcorroy           #+#    #+#             */
/*   Updated: 2024/03/13 13:15:34 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char *store;
static	char *line;

int containsNewline(const char *str)
{
	
    while (*str != '\0')
	{
        if (*str == '\n')
		{
            return 1; // La chaîne contient '\n'
        }
        str++; // Passer au caractère suivant
    }
    return 0; // La chaîne ne contient pas '\n'
}

char *create_line(char *buff, char *store)
{
	char *line;
	int i;
	int j;
	
	line = malloc(sizeof(char) * ft_strlen_until_n(buff));
	j = 0;
	i = 0;
	while(store[i] != '\n')
	{
		line[i] = store[i];
		i++;
	}
	if(store[i] == '\n')
	{
		line[i] = store[i];
		i++;
	}
	return (line);
}

char	*create_store_after_newline(char *buff, char *store)
{
	store = malloc(sizeof(char) * ft_strlen(ft_strchr(buff, 10)));
	if (store == NULL)
		return (NULL);
	store = ft_strchr(buff, 10);
	free(store);
	store = NULL;
	return (store);
}

char	*get_next_line(int fd)
{
	char *buff;
	
	buff = read_file(fd);
	store = ft_strdup(buff);
	
	printf("Contenu lu : %s\n", buff);
	printf("Contenu du store : %s\n", store);
	if(containsNewline(store) == 1)
	{
		line = create_line(buff, store);
		printf("Contenu de la ligne : %s\n", line);
		store = create_store_after_newline(buff, store);
		printf("Contenu du store : %s\n", store);
	}
	else if (containsNewline(store) == 0)
	{
		get_next_line(fd);
	}
	
/* 	int i;
	int j;
	
	j = 0;
	i = 0;
	if(containsNewline(store) == 1)
	{
		while(store[i] != '\n')
		{
			line[i] = store[i];
			i++;
		}
		if(store[i] == '\n')
		{
			line[i] = store[i];
			i++;
		}
		free(store);
		store = NULL;
		printf("Contenu du store après free : %s\n", store);
		printf("Contenu de la ligne : %s\n", line);
		printf("valeur de i : %d\n", i);
		store = malloc(sizeof(char) * (ft_strlen_until_n(buff) - (i) + 1));
		while (buff[i] != '\0')
		{
			store[j] = buff[i];
			j++;
			i++;
		}
		printf("Contenu du store : %s\n", store);
		free(buff); */
/* 	}
 	 else if(containsNewline(store) == 0)
	{
		free(buff);
		buff = malloc(sizeof(char) * BUFFER_SIZE);
		while(containsNewline(store) != 1)
		{
			read(fd, buff, (sizeof(char) * BUFFER_SIZE));
			store = ft_strjoin(store, buff);
			free(buff);
			printf("Contenu du storage : %s\n", store);
		}
	} */
	return (line);
}

int	main(void)
{
	int p = open("text.txt", O_RDONLY);
	if(p == - 1)
		perror("Erreur de l'ouverture du fichier");

	get_next_line(p);
close(p);
}

/* static char *read_file(int fd)
{
	ssize_t bytes_readed;
	char *buff;
	
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (buff == NULL)
		return (NULL);
	bytes_readed = read(fd, buff, (sizeof(char) * BUFFER_SIZE));
	printf("Nombre d'octets lus : %zd\n", bytes_readed);
	printf("Contenu lu : %s\n", buff);
	store = ft_strdup(buff);
	free(buff);
	return (store);
} */