/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 04:50:21 by kali              #+#    #+#             */
/*   Updated: 2022/02/16 18:07:16 by mrojas-e         ###   ########.fr       */
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

long double	atod(char *str, int *error)
{
	int				sign;
	long double		result;
	unsigned long	i;
	long double		j;

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
