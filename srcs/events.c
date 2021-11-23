/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 17:20:24 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/11/23 17:50:53 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	move_camera(t_cop *scop, int key)
{
	switch (key)
	{
		case SDLK_w:
			scop->camera.position.z -= 10;
		break ;
		case SDLK_a:
			scop->camera.position.x -= 10;
		break ;
		case SDLK_s:
			scop->camera.position.z += 10;
		break ;
		case SDLK_d:
			scop->camera.position.x += 10;
		break ;
	}	
}

void	handle_events(t_cop *scop, SDL_Event e)
{
	if (e.key.keysym.sym == SDLK_w || e.key.keysym.sym == SDLK_a || 
		e.key.keysym.sym == SDLK_s || e.key.keysym.sym == SDLK_d)
		 move_camera(scop, e.key.keysym.sym);
}