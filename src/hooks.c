/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:53:23 by hunam             #+#    #+#             */
/*   Updated: 2023/02/21 16:49:58 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_hook(int key_code, t_g *g)
{
	if (key_code == ESC)
		clean_exit(g, 0);
	else if (key_code == K)
		g->is_qwerty = !g->is_qwerty;
	else if (key_code == C)
		g->move_offset = -g->move_offset;
	else if (key_code == M)
		g->zoom = -g->zoom;
	else if (key_code == P)
		p_key(g);
	else
	{
		rt_keys(key_code, g);
		dir_keys(key_code, g);
	}
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_g *g)
{
	static int	nb = 0;

	(void) x;
	(void) y;
	if (nb++ == 0 && (
			(g->scale > 1 && mouse_code == SCROLL_DOWN)
			|| mouse_code == SCROLL_UP
		))
	{
		g->no_color_mode = true;
		draw(g);
		g->no_color_mode = false;
		if (mouse_code == SCROLL_UP)
			g->scale += g->zoom;
		if (mouse_code == SCROLL_DOWN)
			g->scale -= g->zoom;
		if (g->scale < 1)
			g->scale = 1;
		draw(g);
	}
	if (nb == 3)
		nb = 0;
	if (g->scale < 1)
		g->scale = 1;
	return (0);
}

int	maximize_hook(t_g *g)
{
	draw_ui(g);
	draw(g);
	return (0);
}

int	close_hook(t_g *g)
{
	clean_exit(g, 0);
	return (0);
}
