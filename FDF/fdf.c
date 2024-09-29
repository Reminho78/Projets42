/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:18:29 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/30 00:18:57 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_columns(char *line)
{
	int		count;
	char	**split;

	split = ft_split(line, ' ');
	count = 0;
	while (split[count])
		free(split[count++]);
	free(split);
	return (count);
}

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

mlx_image_t	*init_image(mlx_t *mlx, t_map *map)
{
	mlx_image_t	*image;

	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
	{
		free_map(map);
		mlx_terminate(mlx);
		return (NULL);
	}
	ft_memset(image->pixels, 0, image->width * image->height * sizeof(int32_t));
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_delete_image(mlx, image);
		mlx_terminate(mlx);
		free_map(map);
		return (NULL);
	}
	return (image);
}

mlx_t	*init_mlx(t_map *map)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
	{
		free_map(map);
		return (NULL);
	}
	return (mlx);
}

int32_t	main(int argc, char **argv)
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*image;

	map = read_file(argv[1]);
	mlx = init_mlx(map);
	image = init_image(mlx, map);
	if (argc != 2)
		return (1);
	if (!map)
		return (1);
	if (!mlx)
		return (1);
	if (!image)
		return (1);
	draw_map(image, map, 0, 0);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_map(map);
	return (0);
}
