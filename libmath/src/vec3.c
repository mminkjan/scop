/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 19:11:24 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/11/24 15:04:38 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libmath.h"

t_vec3	vec3_negate(t_vec3 v)
{
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	return (v);
}

double	vec3_magnitude(t_vec3 v)
{
	double	magnitude;

	magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (magnitude);
}

t_vec3	vec3_normalize(t_vec3 v)
{
	t_vec3	normalized;
	double	magnitude;

	magnitude = vec3_magnitude(v);
	normalized = v;
	normalized.x /= magnitude;
	normalized.y /= magnitude;
	normalized.z /= magnitude;
	return (normalized);
}

t_vec3 vec3_subtract(t_vec3 a, t_vec3 b)
{
	t_vec3 sub;

	sub = a;
	sub.x -= b.x;
	sub.y -= b.y;
	sub.z -= b.z;
	return (sub);
}

t_vec3 vec3_cross(t_vec3 a, t_vec3 b)
{
	t_vec3 cross;

	cross.x = a.y * b.z - a.z * b.y;
	cross.y = a.z * b.x - a.x * b.z;
	cross.z = a.x * b.y - a.y * b.x;
	return (cross);
}

double vec3_dot(t_vec3 a, t_vec3 b)
{
	double dot;

	dot = a.x * b.x + a.y * b.y + a.z * b.z;  
	return (dot);
}


