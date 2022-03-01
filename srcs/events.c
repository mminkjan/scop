/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 17:20:24 by mminkjan      #+#    #+#                 */
/*   Updated: 2022/03/01 19:53:05 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

static void zoom_camera(t_cop *scop, int key, double dt)
{
	printf("sukkel\n");
	if (key == 61)
		scop->camera.position = vec3_add(vec3_dot_f(scop->camera.direction, scop->camera.speed * dt), scop->camera.position);
	if (key == 45)
		scop->camera.position = vec3_subtract(scop->camera.position, vec3_dot_f(scop->camera.direction, scop->camera.speed * dt));
}

static void	move_camera(t_cop *scop, int key, double dt)
{

	if (key == SDLK_w)
		scop->camera.position = vec3_add(vec3_dot_f(scop->camera.up, scop->camera.speed * dt), scop->camera.position);
	if (key == SDLK_s)
		scop->camera.position = vec3_subtract(scop->camera.position, vec3_dot_f(scop->camera.up, scop->camera.speed * dt));
	if (key == SDLK_d)
		scop->camera.position = vec3_add(vec3_dot_f(vec3_normalize(vec3_cross(scop->camera.direction, scop->camera.up)),  scop->camera.speed * dt), scop->camera.position);
	if (key == SDLK_a)
		scop->camera.position = vec3_subtract(scop->camera.position, vec3_dot_f(vec3_normalize(vec3_cross(scop->camera.direction, scop->camera.up)),  scop->camera.speed * dt));
}

void	handle_events(t_cop *scop, SDL_Event e, double dt)
{
	Uint32 mouse;

	printf("%d\n", e.key.keysym.sym);
	if (e.key.keysym.sym == SDLK_w || e.key.keysym.sym == SDLK_a || 
		e.key.keysym.sym == SDLK_s || e.key.keysym.sym == SDLK_d)
		move_camera(scop, e.key.keysym.sym, dt);
	if ((scop->events.mouse_state & SDL_BUTTON_LMASK) != 0) 
		// printf("mouse button left %d - %d\n", scop->events.cursor_x, scop->events.cursor_y);
	if (e.key.keysym.sym == 61 || e.key.keysym.sym == 45)
		zoom_camera(scop, e.key.keysym.sym, dt);
}