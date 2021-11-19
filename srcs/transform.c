/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 14:16:03 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/11/19 15:19:30 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_mat4	get_projection(t_cop *scop)
{
	GLfloat	r, l;
	GLfloat	t, b;
	GLfloat	scale;
    t_mat4  projection;

	scale = tan(POV * 0.5 * PI / 180) * NEAR; 
	r = scop->image_asp_ratio * scale;
	l = -r;
	t = scale;
	b = -t;

	projection = new_mat4();
	projection.m[0] = 2 * NEAR / (r - l);
	projection.m[5] = 2 * NEAR / (t - b); 
	projection.m[8] = (r + l) / (r - l);
	projection.m[9] = (t + b) / (t - b);
	projection.m[10] = -(FAR + NEAR) / (FAR - NEAR);
	projection.m[11] = -1;
	projection.m[14] = -2 * FAR * NEAR / (FAR - NEAR);
    return (projection);
}

t_mat4	get_view(t_cop *scop)
{
    t_mat4  view;
    
    view = LookAt(scop->cam.pos, scop->cam.dir, scop->cam.up);
	return (view);
}

t_mat4  get_model(t_cop *scop)
{
    t_mat4  position;
    t_mat4  rotation;
    t_mat4  scale;
    t_mat4  model;

    model = new_mat4();
    position = mat4_position(scop->transform[0]);
    rotation = mat4_rotation(scop->transform[1]);
    scale = mat4_scale(scop->transform[2]);
    model = mat4_mutluplication(position, rotation);
    model = mat4_mutluplication(model, scale);
    return (model);
}

void	gen_mvp(t_cop *scop)
{
    t_mat4  model;
    t_mat4  view;
    t_mat4  projection;
    t_mat4  mvp;
    
	get_model(scop);
	get_view(scop);
	get_projection(scop);
    mvp = mat4_mutluplication(model, view);
    mvp = mat4_mutluplication(mvp, projection);
    scop->mvp = mvp;
}
