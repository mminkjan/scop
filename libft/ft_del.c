/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_del.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 15:17:32 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/04 12:44:21 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del(void *data, size_t size)
{
	if (data == NULL)
		return ;
	ft_bzero(data, size);
	free(data);
}
