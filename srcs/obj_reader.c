/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_reader.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 13:26:34 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/09/25 22:35:41 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"

static			t_vec2 get_vec2(char *str)
{
	int			i;
	t_vec2		vector2;
	char		**values;
    
	i = 1;
	values = ft_strsplit(str, ' ');
    vector2.x = ft_atof(values[i]);
	vector2.y = ft_atof(values[i + 1]);
    return (vector2);
}

static			t_vec3 get_vec3(char *str)
{
	int			i;
    t_vec3      vector3;
	char		**values;

    i = 0;
	values = ft_strsplit(str, ' ');
	ft_isdigit(values[0][0]) != 1 ? i++ : 0;
    vector3.x = ft_atof(values[i]);
	vector3.y = ft_atof(values[i + 1]);
	vector3.z = ft_atof(values[i + 2]);
    return (vector3);
}

static void		set_buffer(t_cop *scop, char **obj, t_buffer_data *buffer)
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
			buffer->v[v++] = get_vec3(obj[i]);
		else if (obj[i][0] == 't')
		   buffer->vt[vt++] = get_vec2(obj[i]);
		else if (obj[i][0] == 'n')
			buffer->vn[vn++] = get_vec3(obj[i]);
		i++;
    }
	buffer->points = (GLfloat*)malloc((sizeof(GLfloat) * v) * VDUB);
	buffer->lines = (GLfloat*)malloc((sizeof(GLfloat) * v) * VDUB);
	buffer->triangles = (GLfloat*)malloc((sizeof(GLfloat) * v) * VDUB);
	buffer->squads = (GLfloat*)malloc((sizeof(GLfloat) * v) * VDUB);
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
	set_buffer(scop, obj, buffer);
    close(fd);
	while (obj[face_index] != NULL)
		face_index++;
	obj_parcer(scop, buffer, obj[face_index - 1]);
}
