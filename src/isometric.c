/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:46:30 by hunam             #+#    #+#             */
/*   Updated: 2023/02/21 14:27:47 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_coord	*cart_to_iso_coord(int x, int y, int z, t_uint color)
{
	return (coord(
			x - y,
			(x + y) / 2.0 + z / 2.0,
			color
		));
}

t_coord	*iso_start_coord(t_g *g)
{
	float	drawing_width;
	float	drawing_height;
	float	x_margin;
	float	y_margin;

	drawing_width
		= g->map_height * g->scale + g->map_width * g->scale - 2.0 * g->scale;
	drawing_height = (g->scale
			* (g->map_height + g->map_width + 2.0 * g->map_highest)) / 4.0;
	x_margin = (g->win_width * 0.8 - drawing_width) / 2.0;
	y_margin = (g->win_height - drawing_height) / 2.0;
	return (coord(
			x_margin + g->scale * 2 * (g->map_height / 2.0),
			y_margin + drawing_height * 0.5 + g->scale * (g->map_height / 2.0),
			0
		));
}
