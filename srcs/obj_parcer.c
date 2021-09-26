/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_parcer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 14:56:24 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/09/26 23:35:57 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"




static void		save_triangle(t_cop *scop, char *str, t_buffer_data *data)
{
	char		**group;
    char        **values;
	static int	index = 0;
    int         vt_index;

	group = ft_strsplit(str, ' ');
    values = ft_strsplit(group[0], '/');
    printf("%d\n", index);
	data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].x;
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].y;
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].z;
    values = ft_strsplit(group[1], '/');
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].x;
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].y;
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].z;
    values = ft_strsplit(group[2], '/');
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].x;
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].y;
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].z;
    data->length_tr = index;
    // index++;
    // printf("%d\n", ft_atoi(values[0]));


    // while (*set)
    // {
    //     printf("%s\n", *set);
    //     set++;
    // }
	// printf("%f  -  %f  -  %f\n", data->v[(char)*set[0]- 1].x, data->v[(char)*set[0] - 1].y,  data->v[(char)*set[0] - 1].z);
    // printf("%d\n", ft_atoi(*set[0]));
    // vt_index = ft_atoi(*set[0]);
    // vt_index = ft_atoi(*set[1]);
    // printf("%d\n", vt_index);
    // vt_index = ft_atoi(*set[2]);
    // printf("%d\n", vt_index);
	// printf("%f  -  %f  -  %f\n", data->triangles[index], data->triangles[index + 1],  data->triangles[index + 2]);
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
    int index = 0;
    scop->triangle_data = (GLfloat*)malloc(sizeof(GLfloat) * buffer->length_tr);
    while (index < buffer->length_tr)
    {
        scop->triangle_data[index] = buffer->triangles[index];
        printf("%f\n", buffer->triangles[index]);
        // printf("%d\n", index);
        index++;

    }
    // if (primitive == 1)
    // 	save_point(scop, buffer , *face);
    // else if (primitive == 2)
    //     save_line(scop, obj, *index);
    // else if (primitive == 4)
    //     save_quad(scop, obj, *index);
}
