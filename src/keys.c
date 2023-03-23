/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:09:03 by hunam             #+#    #+#             */
/*   Updated: 2023/02/21 16:49:51 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

bool	is_left(t_g *g, int key)
{
	return (key == ARROW_LEFT
		|| (g->is_qwerty && key == A)
		|| (!g->is_qwerty && key == Q));
}

bool	is_right(t_g *g, int key)
{
	(void) g;
	return (key == ARROW_RIGHT
		|| key == D);
}

bool	is_up(t_g *g, int key)
{
	return (key == ARROW_UP
		|| (g->is_qwerty && key == W)
		|| (!g->is_qwerty && key == Z));
}

bool	is_down(t_g *g, int key)
{
	(void) g;
	return (key == ARROW_DOWN
		|| key == S);
}

bool	is_dir(t_g *g, int key)
{
	return (is_left(g, key)
		|| is_right(g, key)
		|| is_up(g, key)
		|| is_down(g, key));
}
