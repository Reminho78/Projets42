/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:29:48 by rcorroy           #+#    #+#             */
/*   Updated: 2024/08/27 16:21:16 by remidubenar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Alloue (avec malloc(3)) et retourne un tableau
de chaînes de caractères obtenu en séparant ’s’ à
l’aide du caractère ’c’, utilisé comme délimiteur.
Le tableau doit être terminé par NULL. */

static char	**insert_words(char const *s, char c, char **tab, int words)
{
	int	w;
	int	i;
	int	j;

	w = 0;
	i = 0;
	j = 0;
	while (w != words)
	{
		if (s[i] == c && i == 0)
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
		while ((s[i] != c && s[i] != '\0') || (i == 0 && s[i] != '\0'))
		{
			tab[w][j] = s[i];
			i++;
			j++;
		}
		i++;
		tab[w][j] = '\0';
		j = 0;
		w++;
	}
	return (tab);
}

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

int	malloc_string(char **tab, int w, int words_len)
{
	tab[w] = malloc((words_len + 1) * sizeof(char));
	if (!(tab[w]))
	{
		free(tab);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		w;
	int		i;
	int		words_len;

	w = -1;
	i = 0;
	words = count_words(s, c);
	tab = (char **)malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (++w != words)
	{
		words_len = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (((s[i] != c) || (i == 0)) && ++words_len && s[i] != '\0')
			i++;
		if (malloc_string(tab, w, words_len) == 0)
			return (NULL);
	}
	tab[w] = NULL;
	insert_words(s, c, tab, words);
	return (tab);
}
