/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cpyint.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 17:40:52 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/11/02 17:47:40 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_cpyint(int *dst, int *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
