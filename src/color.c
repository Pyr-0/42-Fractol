/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:26:18 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/02/11 20:40:47 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color(int loop_count, int limit, t_param *param)
{
	if (loop_count == limit)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0, 0, 0, 0));
	else if (loop_count > 20)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0, 235, 3, 240));
	else if (loop_count > 30)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0, 100, 40, 233));
	else
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0, 255, 255, 255));
}