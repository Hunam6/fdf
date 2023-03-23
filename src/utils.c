/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:23:53 by hunam             #+#    #+#             */
/*   Updated: 2023/02/23 11:59:58 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_coord	*coord(float x, float y, t_uint color)
{
	t_coord	*out;

	out = malloc(sizeof(t_coord));
	out->x = x;
	out->y = y;
	out->color = color;
	return (out);
}

bool	feq(t_g *g, float a, float b)
{
	if (g->proj == Isometric)
		return (fabs(a - b) < 1);
	return (fabs(a - b) <= 1);
}

double	distance(t_coord *a, t_coord *b)
{
	return (sqrtf(
			(a->x - b->x) * (a->x - b->x)
			+ (a->y - b->y) * (a->y - b->y)
		));
}

int	len_2d(void **obj)
{
	int	out;

	out = 0;
	while (obj[out])
		out++;
	return (out);
}

int	add(int *nb, int add)
{
	*nb += add;
	return (*nb);
}
