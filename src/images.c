/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:39:44 by hunam             #+#    #+#             */
/*   Updated: 2023/02/21 14:27:47 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	switch_to_img(t_g *g, void *img)
{
	g->img2 = g->img;
	g->img = img;
	g->addr = mlx_get_data_addr(
			g->img, &g->bits_per_pixel, &g->size_line, &g->endian);
	if (!g->addr)
		clean_exit(g, 1);
}

void	switch_from_img(t_g *g, void *img)
{
	mlx_destroy_image(g->mlx, img);
	g->img = g->img2;
	g->img2 = NULL;
	g->addr = mlx_get_data_addr(
			g->img, &g->bits_per_pixel, &g->size_line, &g->endian);
	if (!g->addr)
		clean_exit(g, 1);
}
