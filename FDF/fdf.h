/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:32:54 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/30 00:47:59 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define WIDTH 800
# define HEIGHT 600
# define SPACING 30
# define ANGLE 0.7
# define WHITE 0xFFFFFFFF
# define BLUE 0xFF00FF00

typedef struct s_offsets
{
	int	x_offset;
	int	y_offset;
}	t_offsets;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**points;
}	t_map;

typedef struct s_draw_context
{
	mlx_image_t	*img;
	t_map		*map;
	int			x_offset;
	int			y_offset;
}	t_draw_context;

typedef struct s_line
{
	t_point		p1;
	t_point		p2;
	uint32_t	start_color;
	uint32_t	end_color;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			steps;
	int			step_count;
}	t_line;

int			count_columns(char *line);
int			determine_z(char *split);
int			determine_height(char *split);

void		draw_map(mlx_image_t *img, t_map *map, int offset_x, int offset_y);
void		ft_hook(void *param);
void		free_map(t_map *map);
void		process_line(t_map *map, int i, char **split);
void		count_file_dimensions(char *filename, t_map *map);
void		update_coordinates(t_line *line);
void		set_line_params(t_line *line);
void		draw_line(mlx_image_t *img, t_line *line);
void		set_line_points(t_line *line, t_draw_context *ctx, int x, int y);
void		process_lines(t_draw_context *ctx);
void		calculate_offsets(t_map *map, t_offsets *offsets,
				int offset_x, int offset_y);
void		draw_vertical_line(t_draw_context *ctx, int x, int y);
void		draw_horizontal_line(t_draw_context *ctx, int x, int y);
void		set_vertical_line_points(t_line *line,
				t_draw_context *ctx, int x, int y);

t_map		*read_file(char *filename);
t_map		*allocate_map(t_map *map);
t_map		*fill_map(int fd, t_map *map);

uint32_t	interpolate_color(uint32_t start_color,
				uint32_t end_color, float t);

mlx_image_t	*init_image(mlx_t *mlx, t_map *map);

mlx_t		*init_mlx(t_map *map);

#endif