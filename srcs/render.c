/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 17:11:21 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/05/07 17:11:48 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	render(t_cop *scop)
{
	SDL_Event e;
	bool quit = false;
	while (!quit)
	{
    	while (SDL_PollEvent(&e))
		{
        	if (e.type == SDL_QUIT)
            	quit = true;
        	if (e.type == SDL_KEYDOWN)
            	quit = true;
        	if (e.type == SDL_MOUSEBUTTONDOWN)
          		quit = true;
        }
		SDL_UpdateWindowSurface(scop->window);
	}
	SDL_DestroyWindow(scop->window);
}