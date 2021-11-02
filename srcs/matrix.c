/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 14:59:30 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/10/27 15:11:32 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"

t_mat	new_mat4()
{
	t_mat mat;

	mat.m4[0][0] = 1.0;
	mat.m4[0][1] = 0.0;
	mat.m4[0][2] = 0.0;
	mat.m4[0][3] = 0.0;

	mat.m4[1][0] = 0.0;
	mat.m4[1][1] = 1.0;
	mat.m4[1][2] = 0.0;
	mat.m4[1][3] = 0.0;

	mat.m4[2][0] = 0.0;
	mat.m4[2][1] = 0.0;
	mat.m4[2][2] = 1.0;
	mat.m4[2][3] = 0.0;

	mat.m4[3][0] = 0.0;
	mat.m4[3][1] = 0.0;
	mat.m4[3][2] = 0.0;
	mat.m4[3][3] = 1.0;
	return 	(mat);
}