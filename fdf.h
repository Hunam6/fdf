/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:12:13 by etattevi          #+#    #+#             */
/*   Updated: 2023/02/23 12:00:13 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifdef __APPLE__
#  include "minilibx-macos/mlx.h"
# else
#  include "minilibx-linux/mlx.h"
# endif

# include "libft/libft.h"
# include "keycode.h"
# include <fcntl.h>
# include <math.h>

# define COT_ATAN_2 0.5
# define CSC_ATAN_2 1.118033988749894

typedef enum e_proj {
	Isometric = 0,
	Cabinet = 1
}	t_proj;

typedef unsigned int	t_uint;

typedef struct s_coord
{
	float	x;
	float	y;
	t_uint	color;
}	t_coord;

typedef struct s_rect
{
	t_coord	*start;
	int		width;
	int		height;
	int		color;
}	t_rect;

typedef struct s_point
{
	int		z;
	t_uint	color;
}	t_point;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	float	initial_distance;
}	t_line;

typedef struct s_g
{
	int		fd;
	void	*mlx;
	void	*win;

	int		win_width;
	int		win_height;

	t_point	***base_map;
	t_coord	***proj_map;
	t_coord	***proj_map_bak;
	t_proj	proj;
	t_coord	*proj_start;

	int		map_width;
	int		map_height;
	int		map_highest;
	double	scale;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	void	*img2;

	bool	no_color_mode;
	int		move_x;
	int		move_y;
	int		move_offset;
	int		zoom;
	double	rot;
	bool	is_qwerty;
}	t_g;

# ifdef __APPLE__

void	mlx_destroy_mlx(void *mlx);
void	mlx_get_screen_size(void *mlx, int *sizex, int *sizey);

# else

void	mlx_destroy_mlx(void *mlx);

# endif

//colors.c
int		lerp(int a, int b, float f);
int		hex_to_digit(char hex);
t_uint	extract_color(char *str);
t_uint	get_color_at(t_coord *beg, t_coord *end, double initial_distance);

//draw.c
void	put_pixel(t_g *g, int x, int y, t_uint color);
t_line	*init_line(t_g *g, t_coord *beg, t_coord *end);
void	draw_line(t_g *g, t_coord *beg, t_coord *end);
void	draw_half(t_g *g, int offset);
void	draw(t_g *g);

//fdf.c
void	init_mlx(t_g *g, char *file_name);
void	init_fdf(t_g *g, char *file_name);

//free.c
void	free_2d(void **obj, int height);
void	free_map(t_g *g, void ***map);
void	print_err(int code);
void	clean_exit(t_g *g, int exit_code);

//hooks.c
int		key_hook(int key_code, t_g *g);
int		mouse_hook(int button_code, int x, int y, t_g *g);
int		maximize_hook(t_g *g);
int		close_hook(t_g *g);

//images.c
void	switch_to_img(t_g *g, void *img);
void	switch_from_img(t_g *g, void *img);

//isometric.c
t_coord	*cart_to_iso_coord(int x, int y, int z, t_uint color);
t_coord	*iso_start_coord(t_g *g);

//key_hooks.c
void	dir_keys(int key_code, t_g *g);
void	p_key(t_g *g);
void	rt_keys(int key_code, t_g *g);

//oblique.c
t_coord	*cart_to_cab_coord(int x, int y, int z, t_uint color);
t_coord	*cab_start_coord(t_g *g);

//parse.c
void	allocate_n_fill(t_g *g, char **lines);
void	fill_line(t_g *g, char **line, int y);
bool	append(char ***arr, char *el);
void	parse(t_g *g);
double	calc_scale(t_g *g);

//projections.c
void	switch_proj(t_g *g, t_proj proj);
void	create_proj_map(t_g *g,
			t_coord *cart_to_proj_coord(int x, int y, int z, t_uint color));
void	bak_proj_map(t_g *g);

//trbg.c
int		trgb(int t, int r, int g, int b);
int		get_r(int color);
int		get_g(int color);
int		get_b(int color);

//ui.c
t_rect	*init_rect(t_coord *start, int width, int height, t_uint color);
void	draw_rect(t_g *g, t_rect *rect);
void	draw_intructions(t_g *g, const int left);
void	draw_configuration(t_g *g, const int left);
void	draw_ui(t_g *g);

//utils.c
t_coord	*coord(float x, float y, t_uint color);
bool	feq(t_g *g, float a, float b);
double	distance(t_coord *a, t_coord *b);
int		len_2d(void **obj);
int		add(int *nb, int add);

//keys.c
bool	is_left(t_g *g, int key);
bool	is_right(t_g *g, int key);
bool	is_up(t_g *g, int key);
bool	is_down(t_g *g, int key);
bool	is_dir(t_g *g, int key);

#endif