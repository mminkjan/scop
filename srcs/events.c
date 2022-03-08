/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 17:20:24 by mminkjan      #+#    #+#                 */
/*   Updated: 2022/03/08 12:46:09 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

static void rotate_object(t_cop *scop, int delta_x, int delta_y, double dt)
{
    int degrees;
    
    if (delta_x != 0)
    {
        degrees = (scop->transform[1].y * (PI / 180)) + (delta_x / 10);
        scop->transform[1].y = (degrees % 360) / (PI / 180);
    }
}

static void zoom_camera(t_cop *scop, int key, double dt)
{
	if (key == SDLK_i)
		scop->camera.position = vec3_add(vec3_dot_f(scop->camera.direction, scop->camera.speed * dt), scop->camera.position);
	if (key == SDLK_o)
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

	if (e.key.keysym.sym == SDLK_i || e.key.keysym.sym == SDLK_o)
		zoom_camera(scop, e.key.keysym.sym, dt);
	if (e.key.keysym.sym == SDLK_w || e.key.keysym.sym == SDLK_a || 
		e.key.keysym.sym == SDLK_s || e.key.keysym.sym == SDLK_d)
		move_camera(scop, e.key.keysym.sym, dt);
	if ((scop->events.mouse_state & SDL_BUTTON_LMASK) != 0) 
        rotate_object(scop, e.motion.xrel, e.motion.yrel, dt);
}