/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_inits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 04:41:17 by kali              #+#    #+#             */
/*   Updated: 2022/02/15 14:37:37 by mrojas-e         ###   ########.fr       */
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

	dest = paramaters->im_adrss + (y * paramaters->size_line + x * (paramaters->bpp / 8));
	*(unsigned int *)dest = color;
}
