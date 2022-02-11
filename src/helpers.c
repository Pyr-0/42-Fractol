/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 04:50:21 by kali              #+#    #+#             */
/*   Updated: 2022/02/11 20:38:39 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\v'
		|| c == '\n' || c == '\r' || c == '\t')
		return (1);
	return (0);
}

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

 double	atod(char *str, int *error)
{
	int		sign;
	double	result;
	int		i;
	double	j;

	sign = 1;
	result = 0;
	j = 0;
	i = 0;
	sign = ft_inputcheck(str, error);
	while (ft_isspace (str[i]))
		i ++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i++] - '0');
		j++;
	}
	return ((result * pow(0.1, j)) * sign);
}

static void	ft_instructions(void)
{
	printf("Unfortunately your input is not valid.\n");
	printf("Please use one of the following parameters: ");
	printf("[mandelbrot, julia, celtic_mandelbrot, burning_ship]\n");
	printf("Sample usage: ./fractol mandelbrot\n");
}

int	read_input(int argc, char **argv, t_param *param)
{
	int	error;

	error = 0;
	if (argc >= 4)
		ft_instructions();
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
