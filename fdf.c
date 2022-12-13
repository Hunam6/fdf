/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:50:55 by etattevi          #+#    #+#             */
/*   Updated: 2022/12/12 17:31:04 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_coord	*coord(int x, int y)
{
	t_coord	*out;

	out = malloc(sizeof(t_coord));
	out->x = x;
	out->y = y;
	return (out);
}

void	draw_line(t_data *data, t_coord *start, t_coord *end, int color)
{
	int	dx;
	int	dy;
	int	x;
	int	y;

	dx = end->x - start->x;
	dy = end->y - start->y;
	x = start->x;
	while (x <= end->x)
	{
		y = start->y + dy * (x - start->x) / dx;
		mlx_pixel_put(data->mlx, data->win, x, y, color);
		x++;
	}
	free(start);
	free(end);
}

void	draw_vector(t_data *data, t_coord *start, float angle, int length, int color)
{
	const int	x = start->x + cos(angle) * length;
	const int	y = start->y + sin(angle) * length;

	printf("x2: %d, y2: %d\n", x, y);

	draw_line(data, start, coord(x, y), color);
}

int	on_key_pressed(int keycode, void *param)
{
	(void) param;
	if (keycode == 53)
		exit(0);
	return (0);
}
int	close_win(void *param)
{
	(void) param;
	exit(0);
}

int	main(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, 1920, 1080, "FdF");

	ft_printf("x1: %d, y1: %d\n", 200, 500);
	draw_vector(data, coord(200, 400), -atan(0.5), 100, 0x00ffffff);
	ft_printf("--\nx1: %d, y1: %d\n", 200, 400);
	draw_vector(data, coord(200, 500), -atan(0.5), 100, 0x00ffffff);
	ft_printf("--\nx1: %d, y1: %d\n", 200, 500);
	draw_vector(data, coord(200, 500), M_PI / 2.0, 100, 0x00ffffff);
	
	draw_line(data, coord(200, 500), coord(200, 600), 0x00ffffff);

	mlx_hook(data->win, 17, 0, close_win, NULL);
	mlx_key_hook(data->win, on_key_pressed, NULL);
	mlx_loop(data->mlx);
}
