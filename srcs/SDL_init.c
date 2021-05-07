/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_sdl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 17:08:44 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/05/07 17:09:37 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	SDL_init(t_cop *scop)	
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		scop_return_error(scop, SDL_GetError());
	scop->window = SDL_CreateWindow(WINDOW_NAME, \
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	if (scop->window == NULL)
		scop_return_error(scop, SDL_GetError());
	scop->surface = SDL_GetWindowSurface(scop->window);
	if (scop->surface == NULL)
		scop_return_error(scop, SDL_GetError());
}