/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_charcount.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 12:35:18 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/11/02 12:38:21 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charcount(char *str, int c, int len)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0' || i < len)
	{
		if (str[i] == (char)c)
			count++;
		i++;
	}
	return (count);
}
