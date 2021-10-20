/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 14:42:36 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/10/20 13:16:32 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	scop_return_error(t_cop *cop, const char *message)
{
	ft_putendl(message);
	// if (message != NULL)
	// 	free(message);
	exit (0);
}

int		main(int argc, char **argv)
{
	t_cop scop;

	ft_bzero(&scop, sizeof(t_cop));
	SDL_GL_init(&scop);
    get_shaders(&scop);
    obj_reader(&scop, "resources/models/cube.obj");
	render(&scop);
	return (0);
}