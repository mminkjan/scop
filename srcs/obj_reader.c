/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_reader.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 13:26:34 by mminkjan      #+#    #+#                 */
/*   Updated: 2022/03/01 15:40:14 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"


//protection
//duplicated contend in obj file
//multple spaces

static void save_obj(t_cop *scop, t_buffer_data	*buffer)
{
	scop->obj.i = (GLushort*)malloc(sizeof(GLushort) * scop->obj.i_length);
	scop->obj.i = (GLushort*)ft_cpyint((int*)scop->obj.i, (int*)buffer->i, scop->obj.i_length);
	
	scop->obj.v = (GLfloat*)malloc(sizeof(GLfloat) * scop->obj.v_length);
	scop->obj.v = (GLfloat*)ft_cpyfloat(scop->obj.v, buffer->v, scop->obj.v_length);

	scop->obj.vt = (GLfloat*)malloc(sizeof(GLfloat) * scop->obj.vt_length);
	scop->obj.vt = (GLfloat*)ft_cpyfloat(scop->obj.vt, buffer->vt, scop->obj.vt_length);

	scop->obj.vn = (GLfloat*)malloc(sizeof(GLfloat) * scop->obj.vn_length);
	scop->obj.vn = (GLfloat*)ft_cpyfloat(scop->obj.vn, buffer->vn, scop->obj.vn_length);
}

static void		set_center_v(t_cop *scop, GLfloat *buffer)
{
	t_vec3		min;
	t_vec3		max;

	min = vec3_new(buffer[0], buffer[1], buffer[2]);
	max = vec3_new(buffer[0], buffer[1], buffer[2]);
	for (int i = 0; i < scop->obj.v_length; i += 3)
	{
		min.x = buffer[i] < min.x ? buffer[i] : min.x;
		max.x = buffer[i] > max.x ? buffer[i] : max.x;
		min.y = buffer[i + 1] < min.y ? buffer[i + 1] : min.y;
		max.y = buffer[i + 1] > max.y ? buffer[i + 1] : max.y;
		min.z = buffer[i + 2] < min.z ? buffer[i + 2] : min.z;
		max.z = buffer[i + 2] > max.z ? buffer[i + 2] : max.z;
	}
	scop->obj.center = vec3_dot_f(vec3_add(min, max), 0.5);
}

static void get_indices(t_cop *scop, GLushort *buffer, char *str, GLuint *index, int amount)
{
	char		**values;
	GLushort	swap;
	GLuint 		i;

	if (amount > 4)
		scop_return_error(scop, "unable to process amount of vertices\n");
	values = ft_strsplit(str, ' ');
	values++;
	for (int i = 0; i < amount; i++)
	{
    	buffer[(*index)++] = ft_atoi(values[i]) - 1;
	}
	if (amount == 4)
	{
		i = *index;
		swap = buffer[i - 1];
		buffer[i - 1] = buffer[i - 4];
		buffer[i] = buffer[i - 2];
		buffer[i + 1] = swap;
		*index += 2;
	}
}

static void get_values(GLfloat *buffer, char *str, GLuint *index, int amount)
{
	char		**values;

	values = ft_strsplit(str, ' ');
	values++;
	for (int i = 0; i < amount; i++)
    	buffer[(*index)++] = ft_atof(values[i]);
}

void 				obj_reader(t_cop *scop, char *file)
{
    int				fd;
	int				i;
    char			*line;
	t_buffer_data	*buffer;

	i = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        scop_return_error(scop, "unable to open object file\n");
	buffer = (t_buffer_data*)malloc(sizeof(t_buffer_data));
	ft_bzero(&scop->obj, sizeof(t_obj));
	while (get_next_line(fd, &line) > 0)
	{
		if (line[i] == 'v' && line[i + 1] == ' ')
			get_values(buffer->v, line, &scop->obj.v_length, 3);
		else if (line[i] == 'v' && line[i + 1] == 't')
			get_values(buffer->vt, line, &scop->obj.vt_length, 2);
		else if ((line[i] == 'v' && line[i + 1] == 'n'))
			get_values(buffer->vn, line, &scop->obj.vn_length, 3);
		else if ((line[i] == 'f' && line[i + 1] == ' '))
			get_indices(scop, buffer->i, line, &scop->obj.i_length, ft_charcount(line, (int)' ', ft_strlen(line)));
		free(line);
	}
	set_center_v(scop, buffer->v);
	save_obj(scop, buffer);
    close(fd);
}
