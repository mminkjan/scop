/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_parcer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 14:56:24 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/10/06 14:49:25 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"

static void		glfloatncopy(GLfloat *dst, GLfloat *src, size_t len)
{
	for (int i = 0; i < len; i++)
	{
		dst[i] = src[i];
	}
}

static void		set_obj_data(t_cop *scop, t_buffer_data *buffer)
{
	if (buffer->length_pt > 0)
	{
		scop->obj_data.points = (GLfloat*)malloc(sizeof(GLfloat) * buffer->length_pt);
		if (scop->obj_data.points == NULL)
			scop_return_error(scop, "NULL pointer in set_obj_data\n");
		scop->obj_data.points_lenght = buffer->length_pt;
		glfloatncopy(scop->obj_data.points, buffer->points, buffer->length_pt);
		
	}
	if (buffer->length_ln > 0)
	{
		scop->obj_data.lines = (GLfloat*)malloc(sizeof(GLfloat) * buffer->length_ln);
		if (scop->obj_data.lines == NULL)
			scop_return_error(scop, "NULL pointer in set_obj_data\n");
		scop->obj_data.lines_lenght = buffer->length_ln;
		glfloatncopy(scop->obj_data.lines, buffer->lines, buffer->length_ln);
	}
	if (buffer->length_tr > 0)
	{
    	scop->obj_data.triangles = (GLfloat*)malloc(sizeof(GLfloat) * buffer->length_tr);
		if (scop->obj_data.triangles == NULL)
			scop_return_error(scop, "NULL pointer in set_obj_data\n");
		scop->obj_data.triangles_lenght = buffer->length_tr;
		glfloatncopy(scop->obj_data.triangles, buffer->triangles, buffer->length_tr);
	}
	if (buffer->length_sq > 0)
	{
		scop->obj_data.quads = (GLfloat*)malloc(sizeof(GLfloat) * buffer->length_sq);
		if (scop->obj_data.quads == NULL)
			scop_return_error(scop, "NULL pointer in set_obj_data\n");
		scop->obj_data.quads_lenght = buffer->length_sq;
		glfloatncopy(scop->obj_data.quads, buffer->quads, buffer->length_sq);
	}
}

static void		save_point(t_cop *scop, char **faces, t_buffer_data *data)
{
	static int	index = 0;
    char        **values;

    values = ft_strsplit(faces[0], '/');
	data->points[index++] = data->v[ft_atoi(values[0]) - 1].x;
    data->points[index++] = data->v[ft_atoi(values[0]) - 1].y;
    data->points[index++] = data->v[ft_atoi(values[0]) - 1].z;
	data->length_pt = index;
}

static void		save_line(t_cop *scop, char **faces, t_buffer_data *data)
{
	static int	index = 0;
    char        **values;

    values = ft_strsplit(faces[0], '/');
	data->lines[index++] = data->v[ft_atoi(values[0]) - 1].x;
    data->lines[index++] = data->v[ft_atoi(values[0]) - 1].y;
    data->lines[index++] = data->v[ft_atoi(values[0]) - 1].z;
    values = ft_strsplit(faces[1], '/');
    data->lines[index++] = data->v[ft_atoi(values[0]) - 1].x;
    data->lines[index++] = data->v[ft_atoi(values[0]) - 1].y;
    data->lines[index++] = data->v[ft_atoi(values[0]) - 1].z;
	data->length_ln = index;
}

static void		save_triangle(t_cop *scop, char **faces, t_buffer_data *data)
{
	static int	index = 0;
    char        **values;

    values = ft_strsplit(faces[0], '/');
	data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].x;
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].y;
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].z;
	// printf("%f\n", data->triangles[0]);
    values = ft_strsplit(faces[1], '/');
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].x;
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].y;
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].z;
    values = ft_strsplit(faces[2], '/');
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].x;
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].y;
    data->triangles[index++] = data->v[ft_atoi(values[0]) - 1].z;
    data->length_tr = index;
}

static void		save_squad(t_cop *scop, char **faces, t_buffer_data *data)
{
	static int	index = 0;
    char        **values0;
	char        **values2;
	char		**values;


    values0 = ft_strsplit(faces[0], '/');
	data->quads[index++] = data->v[ft_atoi(values0[0]) - 1].x;
    data->quads[index++] = data->v[ft_atoi(values0[0]) - 1].y;
    data->quads[index++] = data->v[ft_atoi(values0[0]) - 1].z;

    values = ft_strsplit(faces[1], '/');
    data->quads[index++] = data->v[ft_atoi(values[0]) - 1].x;
    data->quads[index++] = data->v[ft_atoi(values[0]) - 1].y;
    data->quads[index++] = data->v[ft_atoi(values[0]) - 1].z;
	
    values2 = ft_strsplit(faces[2], '/');
    data->quads[index++] = data->v[ft_atoi(values2[0]) - 1].x;
    data->quads[index++] = data->v[ft_atoi(values2[0]) - 1].y;
    data->quads[index++] = data->v[ft_atoi(values2[0]) - 1].z;
	
    data->quads[index++] = data->v[ft_atoi(values0[0]) - 1].x;
    data->quads[index++] = data->v[ft_atoi(values0[0]) - 1].y;
    data->quads[index++] = data->v[ft_atoi(values0[0]) - 1].z;

	data->quads[index++] = data->v[ft_atoi(values2[0]) - 1].x;
    data->quads[index++] = data->v[ft_atoi(values2[0]) - 1].y;
    data->quads[index++] = data->v[ft_atoi(values2[0]) - 1].z;

	values = ft_strsplit(faces[3], '/');
    data->quads[index++] = data->v[ft_atoi(values[0]) - 1].x;
    data->quads[index++] = data->v[ft_atoi(values[0]) - 1].y;
    data->quads[index++] = data->v[ft_atoi(values[0]) - 1].z;
    data->length_sq = index;
}


static int	get_primitive(char *str)
{
	int		white_space;
	int		i = 0;

	white_space = 0;
	while (str[i])
	{
		if (ft_iswhitespace(str[i]) == 1)
			white_space++;
		i++;
	}
	if (ft_iswhitespace(str[i - 1]) == 1)
		white_space = -1;
	return (white_space);
}

void			obj_parcer(t_cop *scop, t_buffer_data *buffer, char *str)
{
    int         primitive;
	char		**faces;

	faces = ft_strsplit(str, 'f');
	faces++;
	while (*faces != NULL && *faces[0] != ' ')
		faces++;
	while (*faces)
	{
		primitive = get_primitive(*faces);
		switch (primitive)
		{
			case 1:
				save_point(scop, ft_strsplit(*faces, ' '), buffer);
				break;
			case 2:
				save_line(scop, ft_strsplit(*faces, ' '), buffer);
				break;
			case 3:
				save_triangle(scop, ft_strsplit(*faces, ' '), buffer);
				break;
			case 4:
				save_squad(scop, ft_strsplit(*faces, ' '), buffer);
				break;
			default:
				scop_return_error(scop, "invalid amount of primitives\n");
		}
		faces++;
	}
	set_obj_data(scop, buffer);
}
