/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotations.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 15:01:26 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/09/21 16:26:51 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"

void	rotation_x(int degree, t_vec3 *position)
{
    float	prev_y;
	float	prev_z;
	double	radian;

	radian = degree * PI / 180;
	prev_y = position->y;
	prev_z = position->z;
	position->y = prev_y * cos(radian) - prev_z * sin(radian);
	position->z = prev_y * sin(radian) + prev_z * cos(radian);
}

void	rotation_y(int pos, t_vec3 *position)
{
	float	prev_x;
	float	prev_z;
	double	radian;

	radian = pos * PI / 180;
	prev_x = position->x;
	prev_z = position->z;
	position->x = prev_x * cos(radian) + prev_z * sin(radian);
	position->z = -prev_x * sin(radian) + prev_z * cos(radian);
}

void	rotation_z(int pos, t_vec3 *position)
{
	float	prev_x;
	float	prev_y;
	double	radian;

	radian = pos * PI / 180;
	prev_x = position->x;
	prev_y = position->y;
	position->x = prev_x * cos(radian) - prev_y * sin(radian);
	position->y = prev_x * sin(radian) + prev_y * cos(radian);
}

void	iso_projection(t_vec3 *position)
{
	float	prev_x;
	float	prev_y;
	double	angle;

	angle = 30 * PI / 180;
	prev_x = position->x;
	prev_y = position->y;
	position->x = (prev_x - prev_y) * cos(angle);
	position->y = -position->z + (prev_x + prev_y) * sin(angle);
}