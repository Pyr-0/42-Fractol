/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:26:18 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/02/12 18:34:00 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color(int loop_count, int limit, t_param *param)
{
	if (loop_count == limit)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0, 0, 0, 0));
	else if (loop_count >50)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,250, 250, 110));
	else if (loop_count > 40)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,181, 232, 119));
	else if (loop_count > 30)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,1, 221, 125));
	else if (loop_count > 20)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,215, 241, 113));
	else if (loop_count > 10)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,215, 241, 113));
/* 	else if (loop_count > 40)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,181, 232, 119));
	else if (loop_count > 6)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0, 255, 255, 255)); */
	else
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,42, 72, 88));
}

/* void	calc_color(t_param *param)
{
	int r;
	int g;
	int b;

	my_mlx_pixel_put(param, param->x, param->y, create_trgb(0, r, g, b));
}
 */