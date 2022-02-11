/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:00:14 by kali              #+#    #+#             */
/*   Updated: 2022/02/11 18:51:22 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, int limit)
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
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp.real - tmp.imag + c.real;
		tmp.real = z.real * z.real;
		tmp.imag = z.imag * z.imag;
		iter++;
	}
	return (iter);
}

int	julia(t_complex c, int limit, t_param *parameters)
{
	int			iter;
	t_complex	z;
	t_complex	tmp;

	z.real = c.real;
	z.imag = c.imag;
	tmp.real = z.real * z.real;
	tmp.imag = z.imag * z.imag;
	iter = 0;
	while ((tmp.real + tmp.imag <= 8) && iter < limit)
	{
		z.imag = 2 * z.real * z.imag + parameters->julia.imag;
		z.real = tmp.real - tmp.imag + parameters->julia.real;
		tmp.real = z.real * z.real;
		tmp.imag = z.imag * z.imag;
		iter++;
	}
	return (iter);
}

void	draw_fractol(t_param *parameters)
{
	int			loop_count;
	t_complex	parts;
	t_complex	scale;
	int			limit;

	limit = 50;
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
			parameters->x++;
		}
		parameters->y++;
	}
}

/* int main()
{
	int error = 1;
	char *str = "-0.5";

	double temp = 0;
	temp = ft_atod(str, &error);
	if (temp == 0 && error == -1)
		printf("ERROR");
	else 
	printf("%f\n", temp);
	return;
} */