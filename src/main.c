/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:03:51 by kali              #+#    #+#             */
/*   Updated: 2022/02/15 19:50:51 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_param	param;
	
	param.zoom.max_real = 2;
	param.zoom.max_imag =2;
	param.zoom.min_real = -2;
	param.zoom.min_imag = -2;
	read_input(argc, argv, &param);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, WIDTH, HEIGHT, "Fractol!");
	param.img = mlx_new_image(param.mlx, WIDTH, HEIGHT);
	param.im_adrss = mlx_get_data_addr(param.img, &(param.bpp),
			&(param.size_line), &(param.endian));
	draw_fractol(&param);
	mlx_mouse_hook(param.win, mouse_hook, &param);
	mlx_hook(param.win, 17, 0, ft_exit, &param);
	mlx_key_hook(param.win, ft_close, &param);
	mlx_loop(param.mlx);
	exit (0);
}
