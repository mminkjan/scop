/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libmath.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 18:30:30 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/11/02 18:31:13 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

# include <math.h>

typedef struct	s_mat4 {
	float		m[16];
}				t_mat4;

typedef struct	s_mat3 {
	float		m[9];
}				t_mat3;

typedef struct	s_mat2 {
	float		m[4];
}				t_mat2;

typedef struct	s_vec4 {
	float		x;
	float		y;
	float		z;
}				t_vec4;

typedef struct	s_vec3 {
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_vec2 {
	float		x;
	float		y;
}				t_vec2;

double			vec3_magnitude(t_vec3 v);
t_vec3			vec3_normalize(t_vec3 v);
t_vec3			vec3_add(t_vec3 a, t_vec3 b);
t_vec3			vec3_subtract(t_vec3 a, t_vec3 b);
t_vec3			vec3_cross(t_vec3 a, t_vec3 b);
t_vec3			vec3_dot_f(t_vec3 v, float f);
double 			vec3_dot(t_vec3 a, t_vec3 b);
t_vec3			vec3_negate(t_vec3 v);
t_vec3			vec3_new(float x, float y, float z);

t_mat4			LookAt(t_vec3 cam, t_vec3 dir, t_vec3 up);
t_mat4 			mat4_mutliplication(t_mat4 a, t_mat4 b);
t_mat4 			new_mat4();
t_mat4          mat4_position(t_vec3 postion);
t_mat4          mat4_rotation(t_vec3 rotation);
t_mat4          mat4_scale(t_vec3 scale);

#endif
