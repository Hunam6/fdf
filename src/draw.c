/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:12:13 by hunam             #+#    #+#             */
/*   Updated: 2023/02/21 14:27:47 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	put_pixel(t_g *g, int x, int y, t_uint color)
{
	char	*dst;

	if (x < 0 || x > g->win_width * 0.8 - 1 || y < 0 || y > g->win_height)
		return ;
	dst = g->addr + (y * g->size_line + x * (g->bits_per_pixel / 8));
	*(t_uint *)dst = color;
}

t_line	*init_line(t_g *g, t_coord *beg, t_coord *end)
{
	t_line	*out;

	out = malloc(sizeof(t_line));
	if (!out)
		clean_exit(g, 1);
	out->dx = fabs(end->x - beg->x);
	out->dy = fabs(end->y - beg->y);
	out->sx = -1;
	out->sy = -1;
	if (beg->x < end->x)
		out->sx = 1;
	if (beg->y < end->y)
		out->sy = 1;
	out->err = out->dx - out->dy;
	out->initial_distance = -1;
	if (!g->no_color_mode)
		out->initial_distance = distance(beg, end);
	return (out);
}

void	draw_line(t_g *g, t_coord *beg, t_coord *end)
{
	t_line	*line;

	line = init_line(g, beg, end);
	while (42)
	{
		put_pixel(
			g, beg->x, beg->y, get_color_at(beg, end, line->initial_distance));
		if (feq(g, beg->x, end->x) && feq(g, beg->y, end->y))
			break ;
		line->e2 = 2 * line->err;
		if (line->e2 > -line->dy)
		{
			line->err -= line->dy;
			beg->x += line->sx;
		}
		if (line->e2 < line->dx)
		{
			line->err += line->dx;
			beg->y += line->sy;
		}
	}
	free(line);
	free(beg);
	free(end);
}

void	draw_half(t_g *g, int offset)
{
	int		x;
	int		y;
	t_coord	*coord1;
	t_coord	*coord2;

	y = -!offset;
	while (++y < g->map_height)
	{
		x = -offset;
		while (++x < g->map_width)
		{
			coord1 = coord(
					g->proj_start->x + g->proj_map[y - offset][x - !offset]->x
					* g->scale + g->move_x, g->proj_start->y - g->proj_map[y
					- offset][x - !offset]->y * g->scale + g->move_y, g
					->proj_map[y - offset][x - !offset]->color);
			coord2 = coord(g->proj_start->x + g->proj_map[y][x]->x * g->scale
					+ g->move_x, g->proj_start->y - g->proj_map[y][x]->y * g
					->scale + g->move_y, g->proj_map[y][x]->color);
			if (!coord1 || !coord2)
				clean_exit(g, 1);
			draw_line(g, coord1, coord2);
		}
	}
}

void	draw(t_g *g)
{
	draw_half(g, 1);
	draw_half(g, 0);
	mlx_put_image_to_window(g->mlx, g->win, g->img, g->win_width * 0.2, 0);
}
