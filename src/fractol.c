/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:00:14 by kali              #+#    #+#             */
/*   Updated: 2022/02/16 14:33:24 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* int	mandelbrot(t_complex c, int limit)
{
	int			iter;
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
} */

int	mandelbrot(t_complex c, int limit)
{
	int					iter;
	register t_complex	z;
	register t_complex	tmp;

	z.real = c.real;
	z.imag = c.imag;
	tmp.real = z.real * z.real;
	tmp.imag = z.imag * z.imag;
	iter = 0;
	while ((tmp.real + tmp.imag <= 4) && iter < limit)
	{
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp.real - tmp.imag + c.real;
		tmp.real = z.real * z.real;
		tmp.imag = z.imag * z.imag;
		iter++;
	}
	return (iter);
}

int	julia(t_complex c, int limit, t_param *param)
{
	int			iter;
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

void	assignment_trick(size_t *v1, int *v2, int value)
{
	*v1 = value;
	*v2 = value;
}

void	draw_fractol(t_param *param, int limit)
{
	int			loop_count;
	t_complex	parts;
	t_complex	scale;

	assignment_trick(&param->max_iter, &limit, 50);
	scale.real = (param->zoom.max_real - param->zoom.min_real) / WIDTH;
	scale.imag = (param->zoom.max_imag - param->zoom.min_imag) / HEIGHT;
	param->y = 0;
	while (param->y < HEIGHT)
	{
		parts.imag = param->zoom.max_imag - param->y * scale.imag;
		param->x = 0;
		while (param->x < WIDTH)
		{
			parts.real = param->zoom.min_real + param->x * scale.real;
			if (param->fractl_type == JULIA)
				loop_count = julia(parts, limit, param);
			else
				loop_count = mandelbrot(parts, limit);
			set_color(loop_count, limit, param);
			param->x++;
		}
		param->y++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}
