/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_scene.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 16:41:23 by mminkjan      #+#    #+#                 */
/*   Updated: 2022/03/09 16:54:42 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

static void	init_projection(t_cop *scop)
{
	GLfloat	r, l;
	GLfloat	t, b;
	GLfloat	scale;
    t_mat4  projection;

	scale = tan(POV * 0.5 * PI / 180) * NEAR; 
	r = (WIDTH / HEIGHT) * scale;
	l = -r;
	t = scale;
	b = -t;

	scop->camera.projection = new_mat4();
	scop->camera.projection.m[0] = 2 * NEAR / (r - l);
	scop->camera.projection.m[5] = 2 * NEAR / (t - b); 
	scop->camera.projection.m[8] = (r + l) / (r - l);
	scop->camera.projection.m[9] = (t + b) / (t - b);
	scop->camera.projection.m[10] = -(FAR + NEAR) / (FAR - NEAR);
	scop->camera.projection.m[11] = -1;
	scop->camera.projection.m[14] = -2 * FAR * NEAR / (FAR - NEAR);
}

static void	init_view(t_cop *scop)
{
    t_mat4  view;
    
    scop->camera.position.x = 0;
    scop->camera.position.y = 0;
    scop->camera.position.z = 3;

    scop->camera.direction.x = 0;
    scop->camera.direction.y = 0;
    scop->camera.direction.z = -1;

    scop->camera.up.x = 0;
    scop->camera.up.y = 1;
    scop->camera.up.z = 0;
}

static void	init_object(t_cop *scop)
{
    scop->transform[0].x = -scop->obj.pivot.x;
    scop->transform[0].y = -scop->obj.pivot.y;
    scop->transform[0].z = -scop->obj.pivot.z;

    scop->transform[1].x = 0;
    scop->transform[1].y = 0;
    scop->transform[1].z = 0;

    scop->transform[2].x = 1;
    scop->transform[2].y = 1;
    scop->transform[2].z = 1;	
}

void init_scene(t_cop *scop)
{
	init_projection(scop);
	init_view(scop);
	init_object(scop);
	scop->camera.speed = 10;
}

