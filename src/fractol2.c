/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:00:14 by kali              #+#    #+#             */
/*   Updated: 2022/02/12 20:26:57 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, int limit)
{
	int 		iter;
	t_complex	z;

	z.real = c.real;
	z.imag = c.imag;
	iter = 0;
	while ((z.real + z.imag <= 4) && iter < limit)
	{
		z = mandelbrot_basic(z, c);
		iter++;
	}
	return (iter);
}

int	julia(t_complex c, int limit, t_param *param)
{
	int 		iter;
	t_complex	z;
	t_complex	tmp;

	z.real = c.real;
	z.imag = c.imag;
	tmp.real = z.real * z.real;
	tmp.imag = z.imag * z.imag;
	iter = 0;
	while ((tmp.real + tmp.imag <= 4) && iter < limit)
	{
		z.imag = 2 * z.real * z.imag + param->julia.imag;
		z.real = tmp.real - tmp.imag + param->julia.real;
		tmp.real = z.real * z.real;
		tmp.imag = z.imag * z.imag;
		iter++;
	}
	return (iter);
}

void draw_fractol(t_param *param)
{
	int			loop_count;
	t_complex	parts;
	t_complex	scale;
	int			limit;

	limit = 100; 
	// Cordination transformation (step size for each pixel in complex system)
	scale.real = (double)4*0.5/ WIDTH;
	scale.imag = (double)4*0.5/ HEIGHT;
	param->y = 0;
	printf("%d\n", param->fractl_type);
	while (param->y < HEIGHT)
	{
		parts.imag = 2 *0.5 - param->y* scale.imag;
		param->x = 0;
		while (param->x < WIDTH)
		{
			parts.real = -2*0.5 + param->x * scale.real;
			if (param->fractl_type == JULIA)
				loop_count = julia(parts, limit, param);
			else
				loop_count = mandelbrot(parts, limit);
			set_color(loop_count, limit, param);
			param->x++;
		}
		param->y++;
	}
}
