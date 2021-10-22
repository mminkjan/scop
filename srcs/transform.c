/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 14:16:03 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/10/22 16:22:08 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

static void	perspective_projection(t_cop *scop)
{
	float 	n;
	float	f;
	float	r;
	float	l;
	float	t;
	float	b;
	float	scale;
	float	projection[16];

	r = scop->image_asp_ratio * scop->transform[SCALE].x;
	l = -r;
	t = scop->transform[SCALE].x;
	b = t * -1;
	GLuint m_projection = glGetUniformLocation(scop->program_id, "projection");
	//projection x;
	projection[0] = 2 * n / (r - l);
	projection[1] = 0;
	projection[2] = 0;
	projection[3] = 0;

	//projection y
	projection[4] = 0;
	projection[5] = 2 * n / (t - b); 
	projection[6] = 0;
	projection[7] = 0;

	//projection z
	projection[8] = (r + l) / (r - l);
	projection[9] = (t + b) / (t - b);
	projection[10] = -(f + n) / (f - n);
	projection[11] = -1;

	//projection w
	projection[12] = 0;
	projection[13] = 0;
	projection[14] = -2 * f * n / (f - n);
	projection[15] = 0;
	
}

static void translate(t_cop *scop, float *transform)
{
	GLint mTransform = glGetUniformLocation(scop->program_id, "mTransform");
	if (mTransform == -1)
		scop_return_error(scop, "could not find corresponding uniform variable\n");
	// glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));
}

void obj_transform(t_cop *scop)
{
	static float projection[16];
	static float view[16];
	static float model[16];

	GLint mTransform = glGetUniformLocation(scop->program_id, "mTransform");
	if (mTransform == -1)
		scop_return_error(scop, "could not find corresponding uniform variable\n");
	// scale(scop, model);
	// rotate(scop, model);s
	translate(scop, model);
	glUniformMatrix4fv(mTransform, 1, GL_FALSE, model);
}

