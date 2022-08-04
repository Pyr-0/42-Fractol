/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:49:00 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/02/19 20:00:49 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	input_check_rules(int sign_amount, int comma, char *str, int i)
{
	if (i > 16 || sign_amount > 1 || comma > 1 || str[i] != '\0')
		return (-1);
	if (sign_amount == 1 && str[0] != '+' && str[0] != '-')
		return (-1);
	else
		return (0);
}

int	ft_inputcheck(char *str, int *error)
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
	*error = input_check_rules(sign_amount, comma, str, i);
	return (sign);
}

void	ft_instructions(void)
{
	ft_putstr_fd(RED, 1);
	ft_putstr_fd("\n""Unfortunately your input is not valid\n", 1);
	ft_putstr_fd("Please read the following instructions:", 1);
	ft_putstr_fd("\n"MAGENTA"__________________________________________\n""\n"
		"[1] Enter the desired fractol type to output \n", 1);
	ft_putstr_fd(YELLOW"[ mandelbrot ] [ julia ] [ burning_ship] \n", 1);
	ft_putstr_fd(BLUE"Sample usage: ./fractol mandelbrot""\n", 1);
	ft_putstr_fd(MAGENTA, 1);
	ft_putstr_fd("\n""[2]For Julia Fractol select 2 starting values \n", 1);
	ft_putstr_fd(BLUE, 1);
	ft_putstr_fd("Sample usage: ./fractol julia -0.8 -0.15 \n", 1);
	ft_putstr_fd(YELLOW"Here are some Julia sets examples to try:\n", 1);
	ft_putstr_fd(YELLOW"[ 0.12 -0.6 ]  [-0.8 -0.15] [-0.8 -0.175]\n", 1);
	ft_putstr_fd(YELLOW"[0.28 0.008] [0.3 -0.1] [-1.476 0] [-0.624 0.435]\n", 1);
	ft_putstr_fd(MAGENTA, 1);
	ft_putstr_fd("\n""[3] KEY CONTROLS \n", 1);
	ft_putstr_fd(RED"[ MOUSE WEEL ]"RESET"-> Controls Zoom \n", 1);
	ft_putstr_fd(RED"[ KEYS UP/DOWN ]"RESET"-> Controls Iterations \n", 1);
	ft_putstr_fd(RED"[ SPACE BAR ]"RESET"-> Controls Color Shift \n", 1);
	ft_putstr_fd("\n"MAGENTA"     ----- HAVE FUN! :)-----  \n", 1);
}

int	read_input(int argc, char **argv, t_param *param)
{
	int	error;

	error = 0;
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		param->julia.real = atod(argv[2], &error);
		param->julia.imag = atod(argv[3], &error);
		param->fractl_type = JULIA;
		if (error == ERROR)
			ft_error(argc, argv);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12))
		param->fractl_type = BURNINGSHIP;
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		param->fractl_type = MANDELBROT;
	else
		ft_error(argc, argv);
	return (0);
}

void	ft_error(int argc, char **argv)
{
	ft_instructions();
	exit (ERROR);
}
