/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:52:34 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/30 22:26:52 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Compte la largeur et la hauteur de la carte à partir d'un fichier.
// Ouvre le fichier, lit ligne par ligne et compte le nombre de 
// colonnes (largeur) et de lignes (hauteur).
void	count_file_dimensions(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	map->height = 0;
	line = get_next_line(fd);
	if (line)
	{
		map->width = count_columns(line);
		map->height++;
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			map->height++;
	}
	close(fd);
}

//Traite une ligne du fichier et remplit les points dans la structure map.
//Associe les coordonnées x, y et z pour chaque point de la ligne et
//les stocke dans la structure map.
void	process_line(t_map *map, int i, char **split)
{
	int		x;

	x = 0;
	while (split[x])
	{
		map->points[i][x].x = x * SPACING;
		map->points[i][x].y = determine_height(split[x]);
		map->points[i][x].z = determine_z(split[x]);
		free(split[x]);
		x++;
	}
	free(split);
}

//Remplit la structure map avec les points à partir du fichier.
//Lit chaque ligne du fichier, découpe la ligne en points et les passe à 
//process_line pour les stocker dans map. Retourne la map remplie.
t_map	*fill_map(int fd, t_map *map)
{
	int		i;
	char	*line;
	char	**split;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		if (!split)
		{
			free(line);
			return (NULL);
		}
		process_line(map, i, split);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (map);
}

//Alloue la mémoire pour la structure map en fonction de ses dimensions.
//Alloue un tableau de points en fonction de la hauteur (nombre de lignes) et de la largeur (nombre de colonnes) de la carte.
//Retourne la map allouée ou NULL si l'allocation échoue.
t_map	*allocate_map(t_map *map)
{
	int	i;

	map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
	if (!map->points)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		map->points[i] = (t_point *)malloc(sizeof(t_point) * map->width);
		if (!map->points[i])
			return (NULL);
		i++;
	}
	return (map);
}

//read_file - Lit un fichier de carte et remplit la structure map avec les points.
//Ouvre le fichier, compte ses dimensions, alloue la mémoire nécessaire, puis le remplit avec les points.
//Retourne la map remplie ou NULL en cas d'erreur.
t_map	*read_file(char *filename)
{
	int		fd;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	count_file_dimensions(filename, map);
	if (!allocate_map(map))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	fill_map(fd, map);
	close(fd);
	return (map);
}
