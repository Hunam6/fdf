/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:36:33 by hunam             #+#    #+#             */
/*   Updated: 2023/02/23 11:58:32 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	lerp(int a, int b, float f)
{
	return (a + f * (b - a));
}

int	hex_to_digit(char hex)
{
	if (hex <= '9')
		return (hex - 48);
	if (hex <= 'F')
		return (hex - 55);
	return (hex - 87);
}

t_uint	extract_color(char *str)
{
	int		i;
	t_uint	color;
	int		power;

	i = 0;
	color = 0;
	power = 0;
	while (str[i] && str[i] != 'x')
		i++;
	if (!str[i])
		return (0xffffff);
	while (str[i])
		i++;
	while (str[--i] != 'x')
		color += pow(16, power++) * hex_to_digit(str[i]);
	return (color);
}

t_uint	get_color_at(t_coord *beg, t_coord *end, double initial_distance)
{
	double	progress;

	if (initial_distance == -1)
		return (0x00151517);
	if (beg->color == end->color)
		return (beg->color);
	progress = (initial_distance - distance(beg, end)) / initial_distance;
	return (trgb(0,
			lerp(get_r(beg->color), get_r(end->color), progress),
			lerp(get_g(beg->color), get_g(end->color), progress),
			lerp(get_b(beg->color), get_b(end->color), progress)
		));
}
