/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:28:13 by kali              #+#    #+#             */
/*   Updated: 2022/02/12 20:12:01 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>


#define WIDTH 1000
#define HEIGHT 1000
#define MANDELBROT	1
#define JULIA	2

#define WIDTH 1000
#define HEIGHT 1000

#define ESC 53
#define UP_KEY 126
#define DOWN_KEY 125
#define MAGENTA "\e[35m"

typedef struct	s_complex{

	double	real;
	double	imag;
	int		iter;

}t_complex;

typedef struct	s_param	{

	void	*mlx;
	void 	*win;
	void	*img;
	double	zoom_factor;
	int		x;
	int		y;
	int		endian;
	int		fractl_type;
	int		bits_per_pixel;
	int		size_line;
	char	*img_addr;
	t_complex	julia;
	}t_param;

//=========== MLX INITS=======//
int	create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_param *paramaters, int x, int y, int color);

//=========== HELPER FUNCTIONS=======//
int			ft_inputcheck(char *str, int *error);
int			read_input(int argc, char **argv, t_param *param);
double		atod(char *str, int *error);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_multiply(t_complex a, t_complex b);
t_complex	mandelbrot_basic(t_complex z, t_complex c);

//===========FRACTALS=======//

int		mandelbrot(t_complex c, int limit);
int		julia(t_complex c, int limit, t_param *parameters);
void	draw_fractol(t_param *parameters);
void	set_color(int loop_count, int limit, t_param *param);

//===========KEY HOOKS=======//

int	ft_close(int key, t_param *parameters);
void	ft_zoom(int key, t_param *parameters);

#endif