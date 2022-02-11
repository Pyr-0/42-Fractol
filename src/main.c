/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:03:51 by kali              #+#    #+#             */
/*   Updated: 2022/02/08 05:04:32 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"


int main(int argc, char **argv)
{
	t_param parameters;


	parameters.mlx = mlx_init();
	parameters.win = mlx_new_window(parameters.mlx, WIDTH, HEIGHT, "Hello world!");
	parameters.img = mlx_new_image(parameters.mlx, WIDTH, HEIGHT);
	parameters.img_addr = mlx_get_data_addr(parameters.img, &(parameters.bits_per_pixel), &(parameters.size_line), &(parameters.endian));

	read_input(argc, argv, &parameters);
	draw_fractol(&parameters);

	mlx_put_image_to_window(parameters.mlx, parameters.win, parameters.img, 0, 0);
	mlx_key_hook(parameters.win, ft_close, &parameters);
	mlx_loop(parameters.mlx);
}
