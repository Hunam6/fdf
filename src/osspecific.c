/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osspecific.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:15:26 by hunam             #+#    #+#             */
/*   Updated: 2023/02/21 14:27:47 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#ifdef __APPLE__

void	mlx_destroy_mlx(void *mlx)
{
	(void) mlx;
}

void	mlx_get_screen_size(void *mlx, int *sizex, int *sizey)
{
	(void) mlx;
	*sizex = 1440;
	*sizey = 810;
}

#else

void	mlx_destroy_mlx(void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
}

#endif
