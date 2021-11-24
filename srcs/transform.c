/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 14:16:03 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/11/24 16:39:22 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_mat4	get_view(t_cop *scop)
{
    t_mat4  view;

    view = LookAt(scop->camera.position, scop->camera.direction, scop->camera.up);
	printf("%f - %f - %f - %f\n %f - %f - %f - %f\n %f - %f - %f - %f\n %f - %f - %f - %f\n\n", 
		view.m[0], view.m[1], view.m[2], view.m[3], 
		view.m[4], view.m[5], view.m[6], view.m[7], 
		view.m[8],view.m[9] ,view.m[10], view.m[11], 
		view.m[12], view.m[13], view.m[14], view.m[15]);
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
    model = mat4_mutliplication(position, rotation);
    model = mat4_mutliplication(model, scale);
    return (model);
}

void	gen_mvp(t_cop *scop)
{
    t_mat4  model;
    t_mat4  view;
    t_mat4  projection;
    t_mat4  mvp;
    
	model = get_model(scop);
	view = get_view(scop);
    mvp = mat4_mutliplication(model, view);
    mvp = mat4_mutliplication(mvp, scop->camera.projection);
	GLint mvp_i = glGetUniformLocation(scop->program_id, "mvp");
	glUniformMatrix4fv(mvp_i, 1, GL_FALSE, mvp.m);
}
