/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:27:37 by etattevi          #+#    #+#             */
/*   Updated: 2023/02/21 14:38:21 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_mlx(t_g *g, char *file_name)
{
	char	*win_name;

	g->mlx = mlx_init();
	if (!g->mlx)
		clean_exit(g, 1);
	win_name = ft_strjoin("FdF - ", file_name);
	if (!win_name)
		clean_exit(g, 1);
	mlx_get_screen_size(g->mlx, &g->win_width, &g->win_height);
	g->win_width -= 50;
	g->win_height -= 50;
	g->win = mlx_new_window(g->mlx, g->win_width, g->win_height, win_name);
	free(win_name);
	if (!g->win)
		clean_exit(g, 1);
	g->img = mlx_new_image(g->mlx, g->win_width * 0.8, g->win_height);
	if (!g->img)
		clean_exit(g, 1);
	g->addr = mlx_get_data_addr(
			g->img, &g->bits_per_pixel, &g->size_line, &g->endian);
	if (!g->addr)
		clean_exit(g, 1);
}

void	init_fdf(t_g *g, char *file_name)
{
	g->fd = open(file_name, O_RDONLY);
	if (g->fd < 0)
		clean_exit(g, 2);
	g->map_highest = INT_MIN;
	g->img2 = NULL;
	g->move_x = 0;
	g->move_y = 0;
	g->is_qwerty = true;
	g->move_offset = 50;
	g->zoom = 5;
	g->proj_map = NULL;
	g->rot = 0;
}

int	main(int ac, char **av)
{
	t_g	*g;

	if (ac != 2)
		return (ft_printf(
				"Incorrect number of arguments.\n\nUsage:\n\tfdf <file_name>\n"));
	g = ft_calloc(sizeof(t_g), 1);
	if (!g)
		clean_exit(g, 1);
	init_mlx(g, av[1]);
	init_fdf(g, av[1]);
	parse(g);
	switch_proj(g, Isometric);
	mlx_mouse_hook(g->win, mouse_hook, g);
	mlx_hook(g->win, 2, 1L << 0, key_hook, g);
	mlx_hook(g->win, 17, 0, close_hook, g);
	mlx_hook(g->win, 12, 1L << 15, maximize_hook, g);
	mlx_loop(g->mlx);
}
