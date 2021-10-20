/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_reader.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 13:26:34 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/10/20 12:12:06 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"


//protection
//duplicated contend in obj file

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


static void		copy_ushorts(GLushort *dst, GLushort *src, size_t len)
{	
	for (int i = 0; i < len; i++){
		dst[i] = src[i];
	}
}

static void		copy_floats(GLfloat *dst, GLfloat *src, size_t len)
{	
	for (int i = 0; i < len; i++)
	{
		dst[i] = src[i];
	}
}

static void get_values(GLfloat *buffer, char *str, GLuint *index, int amount)
{
	char		**values;

	values = ft_strsplit(str, ' ');
	ft_isdigit(values[0][0]) != 1 ? values++ : 0;
	for (int i = 0; i < amount; i++)
    	buffer[(*index)++] = ft_atof(*values++);
}

static int		convert_quad(t_cop *scop, GLushort *indices, int i)
{
	GLushort swap;

	swap = indices[i - 1];
	indices[i - 1] = indices[i - 4];
	indices[i] = indices[i - 2];
	indices[i + 1] = swap;
	scop->obj.i_length += 2;
	// printf("%u ; %u ; %u ; %u ; %u ; %u\n", indices[i - 4], indices[i - 3], indices[i - 2], indices[i - 1], indices[i], indices[i + 1]);
	return (i + 2);	
}

static void		save_obj_f(t_cop *scop, char *obj, GLushort *indices)
{
	char		**faces;
	int			primitives;
	char		**values;
	char		**face;
	static int	i;

	faces = ft_strsplit(obj, 'f');
	faces++;
	while (*faces != NULL && *faces[0] != ' ')
		faces++;
	while (*faces != NULL)
	{
		values = ft_strsplit(*faces, ' ');
		primitives = get_primitive(*faces);
		if (primitives == 4)
			scop->triangle_fan = true;
		else if (primitives == 2)
			scop->line = true;
		else if (primitives == 1)
			scop->points = true;
		while (*values)
		{
			if (scop->obj.vt_length > 0 || scop->obj.vn_length > 0) {
				face = ft_strsplit(*values, '/');
				indices[i] = (GLushort)ft_atoi(face[0]) - 1;
				for (int i = 0; face[i] != NULL; i++)
					free(face[i]);
			}
			else
				indices[i] = (GLushort)ft_atoi(values[0]) - 1;
			scop->obj.i_length++;
			values++;
			i++;
		}
		faces++;
		if (primitives == 4)
			i = convert_quad(scop, indices, i);
	}
	for (int i = 0; faces[i] != NULL; i++)
		free(faces[i]);
	for (int i = 0; values[i] != NULL; i++)
		free(values[i]);
}

static void		save_obj(t_cop *scop, char **obj, t_buffer_data *buffer)
{
    int         i;
	int			v;
	int			vt;
	static int	vn;
	t_vec3      vertex;

    i = 0;
	v = 0;
	vt = 0;
	vn = 0;
    while (obj[i] != NULL)
    {
    	if (obj[i][0] == ' ')
			get_values(buffer->v, obj[i], &scop->obj.v_length, 3);
		else if (obj[i][0] == 't')
			get_values(buffer->vt, obj[i], &scop->obj.vt_length, 2);
		else if (obj[i][0] == 'n')
			get_values(buffer->vn, obj[i], &scop->obj.vn_length, 3);
		i++;
    }
	save_obj_f(scop, obj[i - 1], buffer->i);
	scop->obj.i = (GLushort*)malloc(sizeof(GLushort) * scop->obj.i_length);
	copy_ushorts(scop->obj.i, buffer->i, scop->obj.i_length);
	scop->obj.v = (GLfloat*)malloc(sizeof(GLfloat) * scop->obj.v_length);
	copy_floats(scop->obj.v, buffer->v, scop->obj.v_length);
	scop->obj.vt = (GLfloat*)malloc(sizeof(GLfloat) * scop->obj.vt_length);
	copy_floats(scop->obj.vt, buffer->vt, scop->obj.vt_length);
	scop->obj.vn = (GLfloat*)malloc(sizeof(GLfloat) * scop->obj.vn_length);
	copy_floats(scop->obj.vn, buffer->vn, scop->obj.vn_length);
	for (int i = 0; i < scop->obj.i_length; i += 3)
		printf("i = %d | %u ; %u ; %u\n",i , scop->obj.i[i], scop->obj.i[i + 1], scop->obj.i[i + 2]);
	for (int i = 0; i < scop->obj.v_length; i += 3)
		printf("i = %d | %f ; %f ; %f\n", i, scop->obj.v[i], scop->obj.v[i + 1], scop->obj.v[i + 2]);
}

void 				obj_reader(t_cop *scop, char *file)
{
    int				fd;
	int				face_index;
    const char		*obj_file;
	t_buffer_data	*buffer;
	char			**obj;

	face_index = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        scop_return_error(scop, "unable to open object file\n");
    file_to_string(scop, fd, &obj_file);
	obj = ft_strsplit(obj_file, 'v');
	buffer = (t_buffer_data*)malloc(sizeof(t_buffer_data));
	ft_bzero(&scop->obj, sizeof(t_obj));
	save_obj(scop, obj, buffer);

    close(fd);
	for (int i = 0; obj[i] != NULL; i++)
		free(obj[i]);
}
