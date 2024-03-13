
#include "get_next_line.h"

char *create_line(int fd, char *store)
{
	char *buff;
	char *line;
	int i;
	int j;
	
	buff = read_file(fd);
	line = malloc(sizeof(char) * ft_strlen_until_n(buff));
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
		free(buff);
	}
	return (line);
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
}
