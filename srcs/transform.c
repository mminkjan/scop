/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 14:16:03 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/10/26 20:15:34 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	set_values_m(t_cop *scop, GLfloat r, GLfloat l, GLfloat t, GLfloat b)
{
	//projection x;
	scop->proj_m[0] = 2 * NEAR / (r - l);
	scop->proj_m[1] = 0;
	scop->proj_m[2] = 0;
	scop->proj_m[3] = 0;

	//projection y
	scop->proj_m[4] = 0;
	scop->proj_m[5] = 2 * NEAR / (t - b); 
	scop->proj_m[6] = 0;
	scop->proj_m[7] = 0;

	//projection z
	scop->proj_m[8] = (r + l) / (r - l);
	scop->proj_m[9] = (t + b) / (t - b);
	scop->proj_m[10] = -(FAR + NEAR) / (FAR - NEAR);
	scop->proj_m[11] = -1;

	//projection w
	scop->proj_m[12] = 0;
	scop->proj_m[13] = 0;
	scop->proj_m[14] = -2 * FAR * NEAR / (FAR - NEAR);
	scop->proj_m[15] = 0;
}

void	init_proj_m(t_cop *scop)
{
	GLfloat	r, l;
	GLfloat	t, b;
	GLfloat	scale;

	scale = tan(POV * 0.5 * PI / 180) * NEAR; 
	r = scop->image_asp_ratio * scale;
	l = -r;
	t = scale;
	b = -t;
	scop->proj_m = (GLfloat*)malloc(sizeof(GLfloat) * 16);
	if (scop->proj_m == NULL)
		scop_return_error(scop, "unable to allocate array\n");
	set_values_m(scop, r, l, t, b);
	GLint m_projection = glGetUniformLocation(scop->program_id, "projection");
	if (m_projection == -1)
		scop_return_error(scop, " ");
	glUniformMatrix4fv(m_projection, 1, GL_FALSE, scop->proj_m);
}

t_vec3	perspective_projection(t_cop *scop, t_vec3 in)
{
	t_vec3	out;

	GLuint m_projection = glGetUniformLocation(scop->program_id, "projection");

	out.x   = in.x * scop->proj_m[0]+ in.y * scop->proj_m[4] + in.z * scop->proj_m[8] + /* in.z = 1 */ scop->proj_m[12];
	out.y   = in.x * scop->proj_m[1] + in.y * scop->proj_m[5] + in.z * scop->proj_m[9] + /* in.z = 1 */ scop->proj_m[13];
	out.z   = in.x * scop->proj_m[2] + in.y * scop->proj_m[6] + in.z * scop->proj_m[10] + /* in.z = 1 */ scop->proj_m[14];
	float w = in.x * scop->proj_m[3] + in.y * scop->proj_m[7] + in.z * scop->proj_m[11] + /* in.z = 1 */ scop->proj_m[15];

	if (w != 1)
	{
		out.x /= w; 
        out.y /= w; 
        out.z /= w; 
	}
	return (out);
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

