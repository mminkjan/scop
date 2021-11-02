/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 14:16:03 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/11/02 18:44:06 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	get_projection(t_cop *scop)
{
	GLfloat	r, l;
	GLfloat	t, b;
	GLfloat	scale;

	scale = tan(POV * 0.5 * PI / 180) * NEAR; 
	r = scop->image_asp_ratio * scale;
	l = -r;
	t = scale;
	b = -t;

	// scop->projection = new_mat4();
	scop->projection.m[0][0] = 2 * NEAR / (r - l);
	scop->projection.m[1][1] = 2 * NEAR / (t - b); 
	scop->projection.m[2][0] = (r + l) / (r - l);
	scop->projection.m[2][1] = (t + b) / (t - b);
	scop->projection.m[2][2] = -(FAR + NEAR) / (FAR - NEAR);
	scop->projection.m[2][3] = -1;
	scop->projection.m[3][2] = -2 * FAR * NEAR / (FAR - NEAR);
}

void	get_view(t_cop *scop)
{
	
}

void	gen_mvp(t_cop *scop)
{
	get_model(scop);
	get_view(scop);
	get_projection(scop);
}


// static void position(t_cop *scop, float *transform)
// {
// 	// glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));
// }

// static void rotation(t_cop *scop, float *transform)
// {
// 	// glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));
// }

// static void scale(t_cop *scop, float *transform)
// {
// 	// glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));
// }



// void obj_transform(t_cop *scop)
// {
// 	static float projection[16];
// 	static float view[16];
// 	static float model[16];

// 	GLint mTransform = glGetUniformLocation(scop->program_id, "mTransform");
// 	if (mTransform == -1)
// 		scop_return_error(scop, "could not find corresponding uniform variable\n");
// 	// scale(scop, model);
// 	// rotate(scop, model);s
// 	translate(scop, model);
// 	glUniformMatrix4fv(mTransform, 1, GL_FALSE, model);
// }

// void	set_perspective(t_cop *scop)
// {
// 	for (int i = 0; i < scop->obj.i_length; i++)
// 	{
		
// 	}
// }

