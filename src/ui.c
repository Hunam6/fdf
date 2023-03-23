/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:12:13 by hunam             #+#    #+#             */
/*   Updated: 2023/02/23 12:03:35 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_rect	*init_rect(t_coord *start, int width, int height, t_uint color)
{
	t_rect	*out;

	out = malloc(sizeof(t_rect));
	out->start = start;
	out->width = width;
	out->height = height;
	out->color = color;
	return (out);
}

void	draw_rect(t_g *g, t_rect *rect)
{
	int	x;
	int	y;

	if (!rect)
		clean_exit(g, 1);
	y = -1;
	while (++y < rect->height)
	{
		x = -1;
		while (++x < rect->width)
			put_pixel(g, rect->start->x + x, rect->start->y + y, rect->color);
	}
	free(rect->start);
	free(rect);
}

void	draw_intructions(t_g *g, const int left)
{
	int	top;

	top = 250;
	mlx_string_put(g->mlx, g->win, left, top, 0xffffff, "Instructions:");
	mlx_string_put(g->mlx, g->win, left, add(&top, 40), 0xffffff,
		"- Move using arrow keys");
	mlx_string_put(g->mlx, g->win, left + 10, add(&top, 30), 0x724cf9, "<");
	mlx_string_put(g->mlx, g->win, left + 30, top, 0xca7df9, "^");
	mlx_string_put(g->mlx, g->win, left + 50, top, 0xedf67d, "v");
	mlx_string_put(g->mlx, g->win, left + 70, top, 0xf896d8, ">");
	mlx_string_put(g->mlx, g->win, left, add(&top, 30), 0xffffff,
		"- Zoom using scroll wheel");
	mlx_string_put(g->mlx, g->win, left + 10, add(&top, 30), 0xca7df9, "^");
	mlx_string_put(g->mlx, g->win, left + 8, top + 3, 0xca7df9, "|");
	mlx_string_put(g->mlx, g->win, left + 12, top + 3, 0xedf67d, "|");
	mlx_string_put(g->mlx, g->win, left + 10, top + 9, 0xedf67d, "v");
	mlx_string_put(g->mlx, g->win, left, add(&top, 40), 0xffffff,
		"- Switch to Cabinet/Isometic projection");
	mlx_string_put(g->mlx, g->win, left + 10, add(&top, 30), 0xf896d8, "p");
	mlx_string_put(g->mlx, g->win, left, add(&top, 40), 0xffffff,
		"- Rotate the drawing");
	mlx_string_put(g->mlx, g->win, left + 10, add(&top, 30), 0xf896d8, "r");
}

void	draw_configuration(t_g *g, const int left)
{
	int	top;

	top = 570;
	mlx_string_put(g->mlx, g->win, left, top, 0xffffff, "Configuration:");
	mlx_string_put(g->mlx, g->win, left, add(&top, 40), 0xffffff,
		"- Toggle keyboard layout");
	mlx_string_put(g->mlx, g->win, left + 10, add(&top, 30), 0xedf67d, "k");
	mlx_string_put(g->mlx, g->win, left, add(&top, 30), 0xffffff,
		"- Toggle mouse wheel mode");
	mlx_string_put(g->mlx, g->win, left + 10, add(&top, 30), 0xca7df9, "m");
	mlx_string_put(g->mlx, g->win, left, add(&top, 30), 0xffffff,
		"- Toggle camera mode");
	mlx_string_put(g->mlx, g->win, left + 10, add(&top, 30), 0xf896d8, "c");
}

void	draw_ui(t_g *g)
{
	t_rect		*rect;
	void		*img;
	int			img_width;
	int			img_height;
	const int	left_margin = 30;

	img = mlx_new_image(g->mlx, g->win_width * 0.2, g->win_height);
	if (!img)
		clean_exit(g, 1);
	switch_to_img(g, img);
	rect = init_rect(
			coord(0, 0, 0), g->win_width * 0.2, g->win_height, 0x00262628);
	draw_rect(g, rect);
	mlx_put_image_to_window(g->mlx, g->win, img, 0, 0);
	switch_from_img(g, img);
	img = mlx_xpm_file_to_image(g->mlx, "fdf.xpm", &img_width, &img_height);
	if (!img)
		clean_exit(g, 3);
	mlx_put_image_to_window(g->mlx, g->win, img, 4, 0);
	mlx_destroy_image(g->mlx, img);
	draw_intructions(g, left_margin);
	draw_configuration(g, left_margin);
	rect = init_rect(
			coord(0, 0, 0), g->win_width * 0.8, g->win_height, 0x00151517);
	draw_rect(g, rect);
}
