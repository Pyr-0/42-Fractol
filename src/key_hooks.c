/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:32:05 by kali              #+#    #+#             */
/*   Updated: 2022/02/12 20:17:22 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(int key, t_param *parameters)
{
	printf ("%d\n" , key);
	if (key == ESC)
	{
		mlx_destroy_window(parameters->mlx, parameters->win);
		exit (0);
	}
	return (0);
}

/*  void	ft_zoom(int key t_param *parameters)
{
	if (key == UP_KEY)
	{
		parameters->zoom_factor *= 0.5;
	}
	if (key == DOWN_KEY)
	{
		parameters->zoom_factor *= 1.5;
	}
	draw_fractol(parameters);
}
 */

