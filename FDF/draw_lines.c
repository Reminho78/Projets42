/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:52:57 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/30 22:38:58 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	interpolate_color(uint32_t start_color, uint32_t end_color, float t)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = ((start_color >> 24) & 0xFF) + t * (((end_color >> 24) & 0xFF)
			- ((start_color >> 24) & 0xFF));
	g = ((start_color >> 16) & 0xFF) + t * (((end_color >> 16) & 0xFF)
			- ((start_color >> 16) & 0xFF));
	b = ((start_color >> 8) & 0xFF) + t * (((end_color >> 8) & 0xFF)
			- ((start_color >> 8) & 0xFF));
	a = (start_color & 0xFF) + t * ((end_color & 0xFF) - (start_color & 0xFF));
	return (r << 24 | g << 16 | b << 8 | a);
}

void	update_coordinates(t_line *line)
{
	int	e2;

	e2 = line->err * 2;
	if (e2 > -line->dy)
	{
		line->err -= line->dy;
		line->p1.x += line->sx;
	}
	if (e2 < line->dx)
	{
		line->err += line->dx;
		line->p1.y += line->sy;
	}
}

void	set_line_params(t_line *line)
{
	line->dx = abs(line->p2.x - line->p1.x);
	line->dy = abs(line->p2.y - line->p1.y);
	if (line->p1.x < line->p2.x)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->p1.y < line->p2.y)
		line->sy = 1;
	else
		line->sy = -1;
	if (line->dx > line->dy)
		line->steps = line->dx;
	else
		line->steps = line->dy;
	line->err = line->dx - line->dy;
	line->step_count = 0;
}

void	draw_line(mlx_image_t *img, t_line *line)
{
	float		t;
	uint32_t	color;

	set_line_params(line);
	while (1)
	{
		t = (float)line->step_count / line->steps;
		color = interpolate_color(line->start_color, line->end_color, t);
		if (line->p1.x >= 0 && line->p1.x < (int)img->width
			&& line->p1.y >= 0 && line->p1.y < (int)img->height)
			mlx_put_pixel(img, line->p1.x, line->p1.y, color);
		if (line->p1.x == line->p2.x && line->p1.y == line->p2.y)
			break ;
		update_coordinates(line);
		line->step_count++;
	}
}
