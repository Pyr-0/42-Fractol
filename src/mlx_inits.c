/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_inits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 04:41:17 by kali              #+#    #+#             */
/*   Updated: 2022/02/08 04:58:49 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_param *paramaters, int x, int y, int color)
{
	char	*dest;

	dest = paramaters->img_addr + (y * paramaters->size_line + x * (paramaters->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}