/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:49:00 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/02/16 18:28:26 by mrojas-e         ###   ########.fr       */
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
	ft_putstr_fd("Unfortunately your input is not valid\n"
		"Please choose one of the following options:\n"
		"__________________________________________\n"
		"\n"MAGENTA"[ Mandelbrot || Julia ] \n"
		"Sample usage: ./fractol mandelbrot or ./fractol julia -1.05 0.05 "
		"by providing the real and imaginary part.\n"
		"Both values should be in the range of -2 to 2.\n", 1);
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
