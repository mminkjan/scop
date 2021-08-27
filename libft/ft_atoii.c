/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoii.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 17:46:28 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/08/27 20:54:59 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static const char		*ft_whitespace(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
	|| str[i] == '\v' || str[i] == '\f')
		i++;
	return (&str[i]);
}

static size_t			ft_isstrlower(const char *str, const char *str2,
						size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && str[i] != '\0')
	{
		if (!(str[i] <= str2[i]))
			return (0);
		i++;
	}
	return (1);
}

static	size_t			ft_exceptional(const char *str, const char sign)
{
	size_t		i;

	i = 0;
	while (ft_isdigit(str[i]) == 1 && i < 19)
	{
		i++;
	}
	if (i == 19 && ft_isdigit(str[i]) == 1)
	{
		if (sign == '-')
			return (0);
		return (-1);
	}
	else if (i == 19)
	{
		if (sign == '-' && ft_isstrlower(str, "9223372036854775808", 19) == 0)
			return (0);
		if (sign != '-' && ft_isstrlower(str, "9223372036854775807", 19) == 0)
			return (-1);
	}
	return (42);
}

int					ft_atoii(const char *str, int *index)
{
    int  i;
	int	n;
    int  s;

	n = 0;
    i = *index;
    s = i;
	str = ft_whitespace(str);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (ft_exceptional(&str[i], str[0]) != 42)
		return (ft_exceptional(&str[i], str[0]));
	while (ft_isdigit(str[i]) == 1)
	{
		n = (str[i] - '0') + n;
		if (ft_isdigit(str[i + 1]) == 1)
			n = (n * 10);
		i++;
	}
	if (str[s] == '-')
		n *= -1;
    *index = i;
	return (n);
}
