/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:32:05 by kali              #+#    #+#             */
/*   Updated: 2022/02/11 16:54:22 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(int key, t_param *parameters)
{
	printf ("%d\n" , key);
	fflush(stdout);
	if (key == 53)
	{
		mlx_destroy_window(parameters->mlx, parameters->win);
		exit (0);
	}
	return (0);
}
