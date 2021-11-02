/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cpyfloat.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 17:31:59 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/11/02 17:39:53 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	*ft_cpyfloat(float *dest, float *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
