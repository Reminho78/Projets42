/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:51:44 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/30 00:28:23 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	determine_height(char *split)
{
	if (split[0] == '1' && split[1] == '0')
		return (35);
	return (0);
}

int	determine_z(char *split)
{
	if (split[0] == '1' && split[1] == '0')
		return (1);
	return (0);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->points[i++]);
	free(map->points);
	free(map);
}

void	set_line_points(t_line *line, t_draw_context *ctx, int x, int y)
{
	line->p1.x = (x - y) * cos(ANGLE) * SPACING + ctx->x_offset;
	line->p1.y = (x + y) * sin(ANGLE) * SPACING
		- ctx->map->points[y][x].y + ctx->y_offset;
	line->p2.x = ((x + 1) - y) * cos(ANGLE) * SPACING + ctx->x_offset;
	line->p2.y = ((x + 1) + y) * sin(ANGLE) * SPACING
		- ctx->map->points[y][x + 1].y + ctx->y_offset;
}

void	set_vertical_line_points(t_line *line,
		t_draw_context *ctx, int x, int y)
{
	line->p1.x = (x - y) * cos(ANGLE) * SPACING + ctx->x_offset;
	line->p1.y = (x + y) * sin(ANGLE) * SPACING
		- ctx->map->points[y][x].y + ctx->y_offset;
	line->p2.x = (x - (y + 1)) * cos(ANGLE) * SPACING + ctx->x_offset;
	line->p2.y = (x + (y + 1)) * sin(ANGLE) * SPACING
		- ctx->map->points[y + 1][x].y + ctx->y_offset;
}
