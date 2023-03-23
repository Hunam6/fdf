/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:36:46 by hunam             #+#    #+#             */
/*   Updated: 2023/02/21 14:27:47 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	allocate_n_fill(t_g *g, char **lines)
{
	char	**line;
	int		y;

	g->base_map = malloc(sizeof(int *) * g->map_height);
	if (!g->base_map)
		clean_exit(g, 1);
	y = -1;
	while (++y < g->map_height)
	{
		line = ft_split(lines[y], ' ');
		if (!line)
			clean_exit(g, 1);
		if (g->map_width == 0)
			g->map_width = len_2d((void **)line);
		g->base_map[y] = malloc(sizeof(t_point *) * g->map_width);
		if (!g->base_map[y])
			clean_exit(g, 1);
		fill_line(g, line, y);
		free_2d((void **)line, g->map_width);
	}
}

void	fill_line(t_g *g, char **line, int y)
{
	int	x;

	x = -1;
	while (++x < g->map_width)
	{
		g->base_map[y][x] = malloc(sizeof(t_point));
		if (!g->base_map[y][x])
			clean_exit(g, 1);
		g->base_map[y][x]->z = ft_atoi(line[x]);
		if (g->base_map[y][x]->z > g->map_highest)
			g->map_highest = g->base_map[y][x]->z;
		g->base_map[y][x]->color = extract_color(line[x]);
	}
}

bool	append(char ***arr, char *el)
{
	char	**out;
	int		i;

	i = 0;
	while ((*arr)[i])
		i++;
	out = malloc(sizeof(char *) * (i + 2));
	if (!out)
		return (false);
	i = -1;
	while ((*arr)[++i])
		out[i] = (*arr)[i];
	out[i++] = el;
	out[i] = NULL;
	free(*arr);
	*arr = out;
	return (true);
}

void	parse(t_g *g)
{
	char	*line;
	char	**lines;

	lines = malloc(sizeof(char *));
	if (!lines)
		clean_exit(g, 1);
	lines[0] = NULL;
	while (1)
	{
		line = get_next_line(g->fd);
		if (!line)
			break ;
		if (!append(&lines, line))
		{
			free(line);
			free_2d((void **)lines, len_2d((void **)lines));
			clean_exit(g, 1);
		}
	}
	g->map_height = len_2d((void **)lines);
	allocate_n_fill(g, lines);
	free_2d((void **)lines, g->map_height);
	g->scale = calc_scale(g);
}

double	calc_scale(t_g *g)
{
	double	scale_width;
	double	scale_height;

	scale_width = ((g->win_width * 0.8) * 2)
		/ (g->map_height + g->map_width);
	scale_height = (g->win_height * 4)
		/ (g->map_height + g->map_width + (2 * g->map_highest));
	if (scale_width < scale_height)
		return (scale_width * 0.5);
	return (scale_height * 0.5);
}
