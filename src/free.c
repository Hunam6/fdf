/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:55:08 by hunam             #+#    #+#             */
/*   Updated: 2023/02/21 14:27:47 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_2d(void **obj, int height)
{
	int	i;

	i = 0;
	while (i < height)
		if (obj[i])
			free(obj[i++]);
	free(obj);
}

void	free_map(t_g *g, void ***map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < g->map_height)
	{
		if (map[y])
		{
			x = -1;
			while (++x < g->map_width)
				if (map[y][x])
					free(map[y][x]);
			free(map[y]);
		}
	}
	free(map);
}

void	print_err(int code)
{
	if (code == 1)
		ft_printf("One allocation failed.\n");
	else if (code == 2)
		ft_printf("Failed to open the file.\n");
	else if (code == 3)
		ft_printf("Failed to import the FdF logo.\n");
}

void	clean_exit(t_g *g, int exit_code)
{
	if (g)
	{
		if (g->fd > 0)
			close(g->fd);
		if (g->win)
			mlx_destroy_window(g->mlx, g->win);
		if (g->img)
			mlx_destroy_image(g->mlx, g->img);
		if (g->img2)
			mlx_destroy_image(g->mlx, g->img2);
		if (g->mlx)
			mlx_destroy_mlx(g->mlx);
		if (g->base_map)
			free_map(g, (void ***)g->base_map);
		if (g->proj_map)
			free_map(g, (void ***)g->proj_map);
		if (g->proj_map_bak)
			free_map(g, (void ***)g->proj_map_bak);
		if (g->proj_start)
			free(g->proj_start);
		free(g);
	}
	print_err(exit_code);
	exit(exit_code);
}
