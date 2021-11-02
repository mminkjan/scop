/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mat4.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 19:30:38 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/11/02 20:27:00 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/mathft.h"

t_mat4	LookAt(t_vec3 cam, t_vec3 dir, t_vec3 up)
{
	t_vec3	axisX;
	t_vec3	axisY;
	t_vec3	axisZ;
	t_mat4	view;

	axisZ = vec3_normalize(vec3_subtract(cam, dir));
	axisX = vec3_normalize(vec3_cross(axisZ, up));
	axisY = vec3_cross(axisX, axisZ);

	view.m[0][0] = axisX.x;
	view.m[0][1] = axisX.y;
	view.m[0][2] = axisX.z;
	view.m[0][3] = -vec3_dot(axisX, cam);

	view.m[1][0] = axisY.x;
	view.m[1][1] = axisY.y;
	view.m[1][2] = axisY.z;
	view.m[1][3] = -vec3_dot(axisY, cam);

	view.m[2][0] = axisZ.x;
	view.m[2][1] = axisZ.y;
	view.m[2][2] = axisZ.z;
	view.m[2][3] = -vec3_dot(axisZ, cam);

	view.m[3][0] = 0;
	view.m[3][1] = 0;
	view.m[3][2] = 0;
	view.m[3][3] = 1;

	return (view);	
}