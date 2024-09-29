/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:52:34 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/30 00:19:12 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
