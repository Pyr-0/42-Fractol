/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:26:18 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/02/15 22:00:36 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* void	set_color(int loop_count, int limit, t_param *param)
{
	if (loop_count == limit)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0, 0, 0, 0));
	else if (loop_count > 30)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,250, 250, 110)); */
	/* else if (loop_count > 40)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,181, 232, 119)); */
/* 	else if (loop_count > 20)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,1, 221, 125));
	else if (loop_count > 10)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,215, 241, 113)); */
	/* else if (loop_count > 10)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,215, 241, 113)); */
/* 	else if (loop_count > 40)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,181, 232, 119));
	else if (loop_count > 6)
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0, 255, 255, 255)); */
/* 	else
		my_mlx_pixel_put(param, param->x, param->y, create_trgb(0,42, 72, 88));
}
 */

/* 
static int	calc_color(t_param *frctl, size_t i);

int	get_color(t_param *frctl)
{
	return (frctl->color_scheme[frctl->iter]);
}

void	set_color_array(t_param *frctl)
{
	size_t	i;

	i = 0;
	while (i <= frctl->max_iter)
	{
		frctl->color_scheme[i] = calc_color(frctl, i);
		i++;
	}
}

static int	calc_color(t_param *frctl, size_t i)
{
	uint8_t	cs;
	uint8_t	rgb[3];
	double	div;

	cs = frctl->color_shift;
	div = (double)i / frctl->max_iter;
	if (frctl->color_shift < 3)
	{
		rgb[cs % 3] = 9 * (1 - div) * pow(div, 3) * 255;
		rgb[(cs + 1) % 3] = 15 * pow((1 - div), 2) * pow(div, 2) * 255;
		rgb[(cs + 2) % 3] = 9 * pow((1 - div), 3) * div * 255;
	}
	else
	{
		cs -= 3;
		rgb[cs % 3] = 9 * pow((1 - div), 3) * div * 255;
		rgb[(cs + 1) % 3] = 15 * pow((1 - div), 2) * pow(div, 2) * 255;
		rgb[(cs + 2) % 3] = 9 * (1 - div) * pow(div, 3) * 255;
	}
	return (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
 */