/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:49:00 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/02/12 20:23:20 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_inputcheck(char *str, int *error)
{
	int		i;
	int		sign_amount;
	int		sign;
	int		comma;

	i = 0;
	comma = 0;
	sign = 1;
	sign_amount = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr("0123456789+-.", str[i]) == 0)
			break ;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = -1;
			sign_amount++;
		}
		if (str[i] == '.')
			comma++;
		i++;
	}
	if (i > 16 || sign_amount > 1 || comma > 1 || str[i] != '\0')
		*error = -1;
	if (sign_amount == 1 && str[0] != '+' && str[0] != '-')
		*error = -1;
	return (sign);
}

int	read_input(int argc, char **argv, t_param *param)
{
	int	error;

	error = 0;
/* 	if (argc >= 4)
		ft_instructions(); */
	if (argc == 4)
	{
		param->julia.real = atod(argv[2], &error);
		param->julia.imag = atod(argv[3], &error);
		param->fractl_type = JULIA;
		if (error == -1)
		{
			printf("Error, check input!");
			return (-1);
		}
	}
	if (argc == 2)
		param->fractl_type = MANDELBROT;
	else
		printf("instructions\n");
	return (0);
}

static void	ft_instructions(void)
{
	printf("Unfortunately your input is not valid\n");
	printf("Please use one of the following parameters: ");
	printf("[mandelbrot, julia, celtic_mandelbrot, burning_ship]\n");
	printf("Sample usage: ./fractol mandelbrot\n");
}

void	error_msg(void)
{
	printf("\033[0;31m");
	printf("Input is not valid\n"
		"Please choose one of the following options:\n"
		"__________________________________________\n"
		"\n"
		"[ Mandelbrot, Julia, BurningShip ]\n"
		"\n"
		"Choose the c value for the Julia fractol "
		"by providing the real and imaginary part.\n"
		"Both values should be in the range of -2 to 2.\n");
}