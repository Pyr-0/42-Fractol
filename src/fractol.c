/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:00:14 by kali              #+#    #+#             */
/*   Updated: 2022/02/17 20:39:03 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	burning_ship(t_complex c, int limit)
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
		z.imag = -2 * fabsl(z.real * z.imag) + c.imag;
		z.real = tmp.real - tmp.imag + c.real;
		tmp.real = z.real * z.real;
		tmp.imag = z.imag * z.imag;
		iter++;
	}
	return (iter);
}
