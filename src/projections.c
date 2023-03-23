/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:06:21 by hunam             #+#    #+#             */
/*   Updated: 2023/02/21 14:27:47 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	switch_proj(t_g *g, t_proj proj)
{
	if (g->proj_map)
		free_map(g, (void ***)g->proj_map);
	if (g->proj_start)
		free(g->proj_start);
	g->proj = proj;
	if (proj == Isometric)
	{
		g->proj_start = iso_start_coord(g);
		create_proj_map(g, cart_to_iso_coord);
	}
	else
	{
		g->proj_start = cab_start_coord(g);
		create_proj_map(g, cart_to_cab_coord);
	}
	if (!g->proj_start)
		clean_exit(g, 1);
	if (g->proj_map_bak)
		free_map(g, (void ***)g->proj_map_bak);
	bak_proj_map(g);
}

void	create_proj_map(
	t_g *g,
	t_coord *cart_to_proj_coord(int x, int y, int z, t_uint color)
)
{
	int	x;
	int	y;

	y = -1;
	g->proj_map = malloc(sizeof(t_coord *) * g->map_height);
	if (!g->proj_map)
		clean_exit(g, 1);
	while (++y < g->map_height)
	{
		x = -1;
		g->proj_map[y] = malloc(sizeof(t_coord *) * g->map_width);
		if (!g->proj_map[y])
			clean_exit(g, 1);
		while (++x < g->map_width)
		{
			g->proj_map[y][x] = cart_to_proj_coord(x, g->map_height - y,
					g->base_map[y][x]->z, g->base_map[y][x]->color);
			if (!g->proj_map[y][x])
				clean_exit(g, 1);
		}
	}
}

void	bak_proj_map(t_g *g)
{
	int	x;
	int	y;

	y = -1;
	g->proj_map_bak = malloc(sizeof(t_coord *) * g->map_height);
	if (!g->proj_map_bak)
		clean_exit(g, 1);
	while (++y < g->map_height)
	{
		x = -1;
		g->proj_map_bak[y] = malloc(sizeof(t_coord *) * g->map_width);
		if (!g->proj_map_bak[y])
			clean_exit(g, 1);
		while (++x < g->map_width)
		{
			g->proj_map_bak[y][x] = malloc(sizeof(t_coord));
			if (!g->proj_map_bak[y][x])
				clean_exit(g, 1);
			ft_memcpy(
				g->proj_map_bak[y][x], g->proj_map[y][x], sizeof(t_coord));
		}
	}
}
