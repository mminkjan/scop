/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/25 19:25:38 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/09/25 20:41:21 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_atof(char *str)
{
	int		sign;
	float	m;
	float	value;

	m = 1;
	sign = 0;
	value = 0;
	while (ft_iswhitespace(*str) == 1)
		str++;
	*str == '-' ? sign = 1 : 0;
	*str == '-' || *str == '+' ? str++ : 0;
	while (*str >= '0' && *str <= '9')
		value = value * 10 + (*str++ - '0');
	if (*str == '.' && (*str++))
		while (*str >= '0' && *str <= '9')
			value += (*str++ - '0') / (m *= 10);
	return (sign == 1 && value > 0 ? -value : value);
}
