/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 14:16:03 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/10/20 18:35:55 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

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

