/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 14:16:03 by mminkjan      #+#    #+#                 */
/*   Updated: 2022/03/09 16:50:11 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_mat4	get_view(t_cop *scop)
{
    t_mat4  view;

    view = LookAt(scop->camera.position, vec3_add(scop->camera.position, scop->camera.direction) , scop->camera.up);
	return (view);
}

t_mat4  get_model(t_cop *scop)
{
    t_mat4  position;
    t_mat4  rotation;
    t_mat4  scale;
    t_mat4  model;
	t_vec3	pivot;

    model = new_mat4();	
    rotation = mat4_rotation(scop->transform[1]);
    scale = mat4_scale(scop->transform[2]);
	position = mat4_position(scop->transform[0]);
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
