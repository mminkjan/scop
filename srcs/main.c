/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 14:42:36 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/09/22 18:12:53 by mminkjan      ########   odam.nl         */
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

int		main(void)
{
	t_cop scop;

      printf("loaded objects\n");
	SDL_GL_init(&scop);
    load_shaders(&scop);
    obj_reader(&scop, "resources/models/cube.obj");
	render(&scop);
	return (0);
}