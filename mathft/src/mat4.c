/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mat4.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 19:30:38 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/11/03 16:58:29 by mminkjan      ########   odam.nl         */
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

	view = new_mat4();
	view.m[0] = axisX.x;
	view.m[1] = axisX.y;
	view.m[2] = axisX.z;
	view.m[3] = -vec3_dot(axisX, cam);

	view.m[4] = axisY.x;
	view.m[5] = axisY.y;
	view.m[6] = axisY.z;
	view.m[7] = -vec3_dot(axisY, cam);

	view.m[8] = axisZ.x;
	view.m[9] = axisZ.y;
	view.m[10] = axisZ.z;
	view.m[11] = -vec3_dot(axisZ, cam);

	return (view);	
}



t_mat4	mat4_rotationX(t_mat4 mat, float angle)
{
	mat.m[5] = cos(angle);
	mat.m[6] = -sin(angle);
	mat.m[9] = sin(angle);
	mat.m[10] = cos(angle);
	return (mat);
}

t_mat4	mat4_rotationY(t_mat4 mat, float angle)
{
	mat.m[0] = cos(angle);
	mat.m[2] = sin(angle);
	mat.m[8] = -sin(angle);
	mat.m[10] = cos(angle);
	return (mat);
}

t_mat4	mat4_rotationZ(t_mat4 mat, float angle)
{
	mat.m[0] = cos(angle);
	mat.m[1] = -sin(angle);
	mat.m[4] = sin(angle);
	mat.m[5] = cos(angle);
	return (mat);
}

t_mat4 mat4_rotation(t_mat4 m, t_vec3 rotation)
{
	t_mat4 rot;

	if (rotation.x != 0)
	{
		rot = mat4_rotationX(new_mat4(), rotation.x);
		m = mat4_mutluplication(m, rot);
	}
	if (rotation.y != 0)
	{
		rot = mat4_rotationY(new_mat4(), rotation.y);
		m = mat4_mutluplication(m, rot);
	}
	if (rotation.z != 0)
	{
		rot = mat4_rotationZ(new_mat4(), rotation.z);
		m = mat4_mutluplication(m, rot);
	}
	return(m);
}
t_mat4 mat4_mutluplication(t_mat4 a, t_mat4 b)
{
	t_mat4 mult;
	
	mult.m[0] = a.m[0] * b.m[0] + a.m[1] * b.m[4]+ a.m[2] * b.m[8] + a.m[3] * b.m[12];
	mult.m[1] = a.m[0] * b.m[1] + a.m[1] * b.m[5] + a.m[2] * b.m[9] + a.m[3] * b.m[13];
	mult.m[2] = a.m[0] * b.m[2] + a.m[1] * b.m[6] + a.m[2] * b.m[10] + a.m[3] * b.m[14];
	mult.m[3] = a.m[0] * b.m[3] + a.m[1] * b.m[7] + a.m[2] * b.m[11] + a.m[3] * b.m[15];
	mult.m[4] = a.m[4] * b.m[0] + a.m[5] * b.m[4] + a.m[6] * b.m[8] + a.m[7] * b.m[12];
	mult.m[5] = a.m[4] * b.m[1] + a.m[5] * b.m[5] + a.m[6] * b.m[9] + a.m[7] * b.m[13];
	mult.m[6] = a.m[4] * b.m[2] + a.m[5] * b.m[6] + a.m[6] * b.m[10] + a.m[7] * b.m[14];
	mult.m[7] = a.m[4] * b.m[3] + a.m[5] * b.m[7] + a.m[6] * b.m[11] + a.m[7] * b.m[15];
	mult.m[8] = a.m[8] * b.m[0] + a.m[9] * b.m[4] + a.m[10] * b.m[8] + a.m[11] * b.m[12];
	mult.m[9] = a.m[8] * b.m[1] + a.m[9] * b.m[5] + a.m[10] * b.m[9] + a.m[11] * b.m[13];
	mult.m[10] = a.m[8] * b.m[2] + a.m[9] * b.m[6] + a.m[10] * b.m[10] + a.m[11] * b.m[14];
	mult.m[11] = a.m[8] * b.m[3] + a.m[9] * b.m[7] + a.m[10] * b.m[11] + a.m[11] * b.m[15];
	mult.m[12] = a.m[12] * b.m[0] + a.m[13] * b.m[4] + a.m[14] * b.m[8] + a.m[15] * b.m[12];
	mult.m[13] = a.m[12] * b.m[1]  + a.m[13] * b.m[5] + a.m[14] * b.m[9] + a.m[15] * b.m[13];
	mult.m[14] = a.m[12] * b.m[2] + a.m[13] * b.m[6] + a.m[14] * b.m[10] + a.m[15] * b.m[14];
	mult.m[15] = a.m[12] * b.m[3] + a.m[13] * b.m[7] + a.m[14] * b.m[11] + a.m[15] * b.m[15];	
	return (mult);
}

t_mat4 new_mat4()
{
	t_mat4 new;

	new.m[0] = 1;
	new.m[1] = 0;
	new.m[2] = 0;
	new.m[3] = 0;

	new.m[4] = 0;
	new.m[5] = 1;
	new.m[6] = 0;
	new.m[7] = 0;

	new.m[8] = 0;
	new.m[9] = 0;
	new.m[10] = 1;
	new.m[11] = 0;

	new.m[12] = 0;
	new.m[13] = 0;
	new.m[14] = 0;
	new.m[15] = 1;

	return (new);
}