/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:00:14 by kali              #+#    #+#             */
/*   Updated: 2022/02/11 20:39:18 by mrojas-e         ###   ########.fr       */
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

int	julia(t_complex c, int limit, t_param *parameters)
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
		z.imag = 2 * z.real * z.imag + parameters->julia.imag;
		z.real = tmp.real - tmp.imag + parameters->julia.real;
		tmp.real = z.real * z.real;
		tmp.imag = z.imag * z.imag;
		iter++;
	}
	return (iter);
}

void draw_fractol(t_param *parameters)
{
	int			loop_count;
	t_complex	parts;
	t_complex	scale;
	int			limit;

	limit = 100; 
	// Cordination transformation (step size for each pixel in complex system)
	scale.real = (double)4 / WIDTH;
	scale.imag = (double)4 / HEIGHT;
	parameters->y = 0;
	printf("%d\n", parameters->fractl_type);
	while (parameters->y < HEIGHT)
	{
		parts.imag = 2 - parameters->y * scale.imag;
		parameters->x = 0;
		while (parameters->x < WIDTH)
		{
			parts.real = -2 + parameters->x * scale.real;
			if (parameters->fractl_type == JULIA)
				loop_count = julia(parts, limit, parameters);
			else
				loop_count = mandelbrot(parts, limit);
			set_color(loop_count, limit, parameters);
			parameters->x++;
		}
		parameters->y++;
	}
}
