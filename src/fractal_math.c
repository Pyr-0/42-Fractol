/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:26:09 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/02/16 18:14:27 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return (result);
}

t_complex	complex_multiply(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real * b.real - a.imag * b.imag;
	result.imag = a.real * b.imag + a.imag * b.real;
	return (result);
}

t_complex	mandelbrot_basic(t_complex z, t_complex c)
{
	t_complex	result;

	result = complex_multiply(z, z);
	result = complex_add(result, c);
	return (result);
}

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
