/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_parcer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 14:56:24 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/09/25 23:05:17 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"




static void		save_triangle(t_cop *scop, char *str, t_buffer_data *data)
{
	char		**set;
	static int	index = 0;

	set = ft_strsplit(str, ' ');

	printf("%f  -  %f  -  %f\n", data->v[(char)*set[0]- 1].x, data->v[(char)*set[0] - 1].y,  data->v[(char)*set[0] - 1].z);
	data->triangles[index] = data->v[(char)*set[0]- 1].x;
    data->triangles[index + 1] = data->v[(char)*set[0] - 1].y;
    data->triangles[index + 2] = data->v[(char)*set[0] - 1].z;
    data->triangles[index + 3] = data->v[(char)*set[1] - 1].x;
    data->triangles[index + 4] = data->v[(char)*set[1] - 1].y;
    data->triangles[index + 5] = data->v[(char)*set[1] - 1].z;
    data->triangles[index + 6] = data->v[(char)*set[2] - 1].x;
    data->triangles[index + 7] = data->v[(char)*set[2] - 1].y;
    data->triangles[index + 8] = data->v[(char)*set[2] - 1].z;
	index += 9;
	printf("%f  -  %f  -  %f\n", data->triangles[index], data->triangles[index + 1],  data->triangles[index + 2]);
}

static int	get_primitive(char *str)
{
	int		white_space;

	white_space = 0;
	while (*str)
	{
		if (ft_iswhitespace(*str) == 1)
			white_space++;
		str++;
	}
	// printf("%d\n", white_space);
	return (white_space);
}

void			obj_parcer(t_cop *scop, t_buffer_data *buffer, char *str)
{
    int         primitive;
	char		**faces;

	faces = ft_strsplit(str, 'f');
	while (*faces != NULL && *faces[0] != ' ')
		faces++;
	while (*faces)
	{
		// printf("%s\n", *faces);
		primitive = get_primitive(*faces);
		if (primitive == 3)
			save_triangle(scop, *faces, buffer);
		faces++;
	}
    // if (primitive == 1)
    // 	save_point(scop, buffer , *face);
    // else if (primitive == 2)
    //     save_line(scop, obj, *index);
    // else if (primitive == 4)
    //     save_quad(scop, obj, *index);
}
