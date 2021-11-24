/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mat4.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 19:30:38 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/11/24 17:21:00 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libmath.h"


t_mat4	LookAt(t_vec3 cam, t_vec3 dir, t_vec3 up)
{
	t_vec3	axisX;
	t_vec3	axisY;
	t_vec3	axisZ;
	t_mat4	translate;
	t_mat4	rotate;

	axisZ = vec3_normalize(vec3_subtract(dir,cam));
	axisX = vec3_normalize(vec3_cross(axisZ, up));
	axisY = vec3_cross(axisX, axisZ);

	translate = new_mat4();
	translate.m[0] = axisX.x;
	translate.m[1] = axisY.x;
	translate.m[2] = axisZ.x;

	translate.m[4] = axisX.y;
	translate.m[5] = axisY.y;
	translate.m[6] = axisZ.y;

	translate.m[8] = axisX.z;
	translate.m[9] = axisY.z;
	translate.m[10] = axisZ.z;

	rotate = new_mat4();
	rotate.m[3] = -cam.x;
	rotate.m[7] = -cam.y;
	rotate.m[11] = -cam.z;

	return (mat4_mutliplication(translate, rotate));	
}

t_mat4 LookAt2(t_vec3 cam, t_vec3 dir, t_vec3 up)
{
	t_vec3	axisX;
	t_vec3	axisY;
	t_vec3	axisZ;
	t_mat4	view;

	axisZ = vec3_normalize(vec3_subtract(dir,cam));
	axisX = vec3_normalize(vec3_cross(up, axisZ));
	axisY = vec3_cross(axisZ, axisX);

	view.m[0] = axisX.x;
	view.m[1] = axisY.x;
	view.m[2] = axisZ.x;
	view.m[4] = axisX.y;
	view.m[5] = axisY.y;
	view.m[6] = axisZ.z;
	view.m[8] = axisX.z;
	view.m[9] = axisY.z;
	view.m[10] = axisZ.z;;
	view.m[12] = -vec3_dot(axisX, cam);
	view.m[13] = -vec3_dot(axisY, cam);
	view.m[14] = -vec3_dot(axisZ, cam);
	return (view);
}

t_mat4  mat4_position(t_vec3 postion)
{
    t_mat4  new;

    new = new_mat4();
    new.m[3] = postion.x;
    new.m[7] = postion.y;
    new.m[11] = postion.z;
    return (new);
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

t_mat4 mat4_rotation(t_vec3 rotation)
{
	t_mat4 new;

    new = new_mat4();
	if (rotation.x != 0)
		new = mat4_rotationX(new, rotation.x);
	if (rotation.y != 0)
		new = mat4_rotationY(new, rotation.y);
	if (rotation.z != 0)
		new = mat4_rotationZ(new, rotation.z);
	return(new);
}

t_mat4  mat4_scale(t_vec3 scale)
{
    t_mat4  new;

    new = new_mat4();
    new.m[0] = scale.x;
    new.m[5] = scale.y;
    new.m[10] = scale.z;
    return (new);
}

t_mat4 mat4_mutliplication(t_mat4 a, t_mat4 b)
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

t_mat4    new_mat4()
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