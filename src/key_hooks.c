/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:22:47 by hunam             #+#    #+#             */
/*   Updated: 2023/02/21 16:49:55 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	dir_keys(int key_code, t_g *g)
{
	if (is_dir(g, key_code))
	{
		g->no_color_mode = true;
		draw(g);
		g->no_color_mode = false;
		if (is_left(g, key_code))
			g->move_x -= g->move_offset;
		else if (is_right(g, key_code))
			g->move_x += g->move_offset;
		else if (is_up(g, key_code))
			g->move_y -= g->move_offset;
		else if (is_down(g, key_code))
			g->move_y += g->move_offset;
		draw(g);
	}
}

void	p_key(t_g *g)
{
	g->no_color_mode = true;
	draw(g);
	g->no_color_mode = false;
	g->proj = !g->proj;
	switch_proj(g, g->proj);
	g->rot = 0;
	draw(g);
}

void	rt_keys(int key_code, t_g *g)
{
	int	i;
	int	j;

	if (key_code == R)
	{
		g->no_color_mode = true;
		draw(g);
		g->no_color_mode = false;
		g->rot -= M_PI_4 / 2;
		i = -1;
		while (++i < g->map_height)
		{
			j = -1;
			while (++j < g->map_width)
			{
				g->proj_map[i][j]->x = g->proj_map_bak[i][j]->x * cos(g->rot)
					- g->proj_map_bak[i][j]->y * sin(g->rot);
				g->proj_map[i][j]->y = g->proj_map_bak[i][j]->x * sin(g->rot)
					+ g->proj_map_bak[i][j]->y * cos(g->rot);
			}
		}
		draw(g);
	}
}
