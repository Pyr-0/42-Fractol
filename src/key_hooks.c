/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:32:05 by kali              #+#    #+#             */
/*   Updated: 2022/02/15 19:50:03 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(int key, t_param *parameters)
{
	printf ("%d\n", key);
	if (key == ESC)
	{
		mlx_destroy_window(parameters->mlx, parameters->win);
		exit (0);
	}
	return (0);
}

int	ft_exit(t_param *param)
{
	exit (0);
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

int	mouse_hook(int	mousecode, int x, int y, t_param *param)
{
	if (mousecode == WHEEL_UP || mousecode == WHEEL_DOWN)
		set_zoom(mousecode, &x, &y, param);
	return (0);
}

 void	set_zoom(int mousecode, int *x, int *y, t_param *param)
{
	double	zoom;
	double	r_pos;
	double	i_pos;

	if (mousecode == WHEEL_DOWN)
		zoom = 0.833;
	if (mousecode == WHEEL_UP)
		zoom = 1.2;
	r_pos = param->zoom.min_real + (double) * x / (WIDTH - 1)
		* (param->zoom.max_real - param->zoom.min_real);
	i_pos = param->zoom.max_imag - (double) * y / (HEIGHT - 1)
		* (param->zoom.max_imag - param->zoom.min_imag);
	param->zoom.max_real = r_pos + (param->zoom.max_real - r_pos) * zoom;
	param->zoom.min_real = r_pos + (param->zoom.min_real - r_pos) * zoom;
	param->zoom.max_imag = i_pos + (param->zoom.max_imag - i_pos) * zoom;
	param->zoom.min_imag = i_pos + (param->zoom.min_imag - i_pos) * zoom;
	draw_fractol(param);
} 
