/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:26:27 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/30 01:10:27 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// Calcul des coordonnées isométriques pour p1 et p2
// Définir la couleur pour p1
// La couleur de fin reste blanche
// Dessiner la ligne
void	draw_horizontal_line(t_draw_context *ctx, int x, int y)
{
	t_line	line;

	line.p1.x = (x - y) * cos(ANGLE) * SPACING + ctx->x_offset;
	line.p1.y = (x + y) * sin(ANGLE)
		* SPACING - ctx->map->points[y][x].y + ctx->y_offset;
	line.p2.x = ((x + 1) - y) * cos(ANGLE) * SPACING + ctx->x_offset;
	line.p2.y = ((x + 1) + y) * sin(ANGLE)
		* SPACING - ctx->map->points[y][x + 1].y + ctx->y_offset;
	if (ctx->map->points[y][x].z > 0 || ctx->map->points[y][x + 1].z > 0)
		line.start_color = BLUE;
	else
		line.start_color = WHITE;
	line.end_color = WHITE;
	draw_line(ctx->img, &line);
}

void	draw_vertical_line(t_draw_context *ctx, int x, int y)
{
	t_line	line;

	line.p1.x = (x - y) * cos(ANGLE) * SPACING + ctx->x_offset;
	line.p1.y = (x + y) * sin(ANGLE)
		* SPACING - ctx->map->points[y][x].y + ctx->y_offset;
	line.p2.x = (x - (y + 1)) * cos(ANGLE) * SPACING + ctx->x_offset;
	line.p2.y = (x + (y + 1)) * sin(ANGLE)
		* SPACING - ctx->map->points[y + 1][x].y + ctx->y_offset;
	if (ctx->map->points[y][x].z > 0 || ctx->map->points[y + 1][x].z > 0)
		line.start_color = BLUE;
	else
		line.start_color = WHITE;
	line.end_color = WHITE;
	draw_line(ctx->img, &line);
}

void	process_lines(t_draw_context *ctx)
{
	int	y;
	int	x;

	y = 0;
	while (y < ctx->map->height)
	{
		x = 0;
		while (x < ctx->map->width)
		{
			if (x < ctx->map->width - 1)
				draw_horizontal_line(ctx, x, y);
			if (y < ctx->map->height - 1)
				draw_vertical_line(ctx, x, y);
			x++;
		}
		y++;
	}
}

void	calculate_offsets(t_map *map, t_offsets *offsets,
		int offset_x, int offset_y)
{
	int	total_width;
	int	total_height;

	total_width = ((map->width - 1)
			- (map->height - 1)) * SPACING * cos(ANGLE);
	total_height = ((map->width - 1)
			+ (map->height - 1)) * SPACING * sin(ANGLE);
	offsets->x_offset = (WIDTH - total_width) / 2 + offset_x;
	offsets->y_offset = (HEIGHT - total_height) / 2 + offset_y;
}

// Calcul des offsets en fonction des dimensions de la carte
// Initialisation du contexte
// Appel de la fonction de traitement des lignes
void	draw_map(mlx_image_t *img, t_map *map, int offset_x, int offset_y)
{
	t_draw_context	ctx;
	t_offsets		offsets;

	calculate_offsets(map, &offsets, offset_x, offset_y);
	ctx.img = img;
	ctx.map = map;
	ctx.x_offset = offsets.x_offset;
	ctx.y_offset = offsets.y_offset;
	process_lines(&ctx);
}
