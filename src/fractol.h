/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:28:13 by kali              #+#    #+#             */
/*   Updated: 2022/02/15 21:59:17 by mrojas-e         ###   ########.fr       */
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

# define WIDTH 1000
# define HEIGHT 1000
# define MANDELBROT	1
# define JULIA	2
# define ERROR -1

# define WIDTH 1000
# define HEIGHT 1000 
# define ESC 53
# define UP_KEY 126
# define DOWN_KEY 125
# define WHEEL_DOWN 4
# define WHEEL_UP 5 
# define MAGENTA "\e[35m"
# define RED = "\e[41m"
# define RESET = "\e[0m"

typedef struct s_complex{
	double	real;
	double	max_real;
	double	min_real;
	double	max_imag;
	double	min_imag;
	double	imag;
	int		iter;
}t_complex;

typedef struct s_param{
	void		*mlx;
	void		*win;
	void		*img;
	double		zoom_factor;
	int			x;
	int			y;
	int			endian;
	int			*color_scheme;
	int 		color_shift;
	int			fractl_type;
	int			bpp;
	int			size_line;
	char		*im_adrss;
	size_t		iter;
	size_t		max_iter;
	t_complex	julia;
	t_complex	zoom;
}t_param;

//=========== MLX INITS=======//
int			create_trgb(int t, int r, int g, int b);
void		my_mlx_pixel_put(t_param *paramaters, int x, int y, int color);

//=========== HELPER FUNCTIONS=======//
double		atod(char *str, int *error);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_multiply(t_complex a, t_complex b);
t_complex	mandelbrot_basic(t_complex z, t_complex c);

//===========FRACTALS=======//

int			mandelbrot(t_complex c, int limit);
int			julia(t_complex c, int limit, t_param *parameters);
void		draw_fractol(t_param *parameters);
void		set_color(int loop_count, int limit, t_param *param);
void		set_color_array(t_param *frctl);
int			get_color(t_param *frctl);

//===========KEY HOOKS=======//

int			ft_close(int key, t_param *parameters);
int			ft_exit(t_param *param);
int			mouse_hook(int mousecode, int x, int y, t_param *param);
void		set_zoom(int mousecode, int *x, int *y, t_param *param);

//===========INPUT CHECK=======//

int			ft_inputcheck(char *str, int *error);
int			read_input(int argc, char **argv, t_param *param);
void		ft_error(int argc, char **argv);


#endif