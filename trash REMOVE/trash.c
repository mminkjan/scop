# include "../includes/scop.h"

t_vec4 get_obj_faces(t_cop *scop, const char *obj, int *index)
{
    t_vec4 face;
    int     i;

    i = *index;;
    i += 2;
    // sprintf("%s\n", obj);
 

    face.x = ft_atoii(obj, &i);
    i++;
    if (ft_isdigit(obj[i]) > 0)
        face.y = ft_atoii(obj, &i);
    i++;
    if (ft_isdigit(obj[i]) > 0)
        face.z = ft_atoii(obj, &i);
    i++;
    if (ft_isdigit(obj[i]) > 0)
        face.w = (float)ft_atoii(obj, &i);
    // printf("%d, %d, %d, %d\n", face.x, face.y, face.z, face.w);
    *index = i;
    return (face);
}

void set_data_vt3(t_cop *scop, t_vec4 face, t_vec3 *vertices, int index)
{
    // scop->vt3_buffer_data[index] = vertices[face.x].x;
    // scop->vt3_buffer_data[index + 1] = vertices[face.x].y;
    // scop->vt3_buffer_data[index + 2] = vertices[face.x].z;
    // scop->vt3_buffer_data[index + 3] = vertices[face.y].x;
    // scop->vt3_buffer_data[index + 4] = vertices[face.y].y;
    // scop->vt3_buffer_data[index + 5] = vertices[face.y].z;
    // scop->vt3_buffer_data[index + 6] = vertices[face.z].x;
    // scop->vt3_buffer_data[index + 7] = vertices[face.z].y;
    // scop->vt3_buffer_data[index + 8] = vertices[face.z].z;

}

void obj_arrange_vertices(t_cop *scop, t_vec3 *vertices, t_vec4 *faces, int fc_lenght)
{
    int vt3_i;
    int vt4_i;
    int fcs_i;
    t_vec4 face;
    t_vec3 vertex;


    vt3_i = 0;
    vt4_i = 0;
    fcs_i = 0;

    while (fcs_i < fc_lenght)
    {

        face = faces[fcs_i];
        if (face.y == -1)
        {
            // set_data_vt1(scop, face, vertices, vt3_i);
        }
        if (face.z == -1)
        {
            // set_data_vt2(scop, face, vertices, vt3_i);
            vt3_i += 3;
        }
        if (face.w == -1)
        {
            // set_data_vt3(scop, face, vertices, vt3_i);
            vt3_i += 3;
        }
        fcs_i++;
    }
}

GLfloat *vector3_to_float_array(t_cop *scop, t_vec3 *buffer, float *data, int length)
{
    t_vec3 vector3;
    int i;
    int f;

    i = 0;
    f = 0;
    while (i < length)
    {
        vector3 = buffer[i];
        data[f] = vector3.x;
        data[f + 1] = vector3.y;
        data[f + 2] = vector3.z;
        i++;
        f += 3;
    }
    
    return (data);
}

float get_float_value(t_cop *scop, const char *obj, int *index)
{
    float   base;
    float   value;
    int     s;
    int     i;

    s = *index;
    i = *index;
    base = (float)ft_atoii(obj, &i);
    while (obj[i] != '.')
    {
        i++;
        if (ft_isalpha(obj[i]) > 0)
            scop_return_error(scop, "error in obj fille\n");
    }
    i++;
    value = ft_atoii(obj, &i);
    value /= 1000000;
    if (obj[s] == '-')
        value *= -1;
    *index = i;
    return (base + value);
}

t_vec3 get_vertex(t_cop *scop, const char *obj, int *index)
{
    t_vec3      vertex;
    int         i;
	char		**segments;
    
    i = *index;
    i += 2;
	// segment = ft_strsplit()
    vertex.x = get_float_value(scop, obj, &i);
    i++;
    vertex.y = get_float_value(scop, obj, &i);
    i++;
    vertex.z = get_float_value(scop, obj, &i);
    // printf("%f, %f, %f\n", vertex.x, vertex.y, vertex.z);
    *index = i - 1;
    return (vertex);
}

static int		get_obj_vertices(t_cop *scop, const char *obj)
{
    int         i;
    int         v;
    int         f;
    t_vec3      bufferv[100000];
    t_vec4      bufferf[100000];
    

    i = 0;
    v = 0;
    f = 0;
    while (obj[i] != '\0' && (obj[i] == 'f' && obj[i + 1] == ' '))
    {
        if (obj[i] == 'v' && obj[i + 1] == ' ')
        {
            bufferv[v] = get_vertex(scop, obj, &i);
            v++;
        }
        i++;
    }
	return (i);
}

// t_vec3	perspective_projection(t_cop *scop, t_vec3 in)
// {
// 	t_vec3	out;
// 	mat4x4 

// 	GLuint m_projection = glGetUniformLocation(scop->program_id, "projection");

// 	out.x   = in.x * scop->proj_m[0]+ in.y * scop->proj_m[4] + in.z * scop->proj_m[8] + /* in.z = 1 */ scop->proj_m[12];
// 	out.y   = in.x * scop->proj_m[1] + in.y * scop->proj_m[5] + in.z * scop->proj_m[9] + /* in.z = 1 */ scop->proj_m[13];
// 	out.z   = in.x * scop->proj_m[2] + in.y * scop->proj_m[6] + in.z * scop->proj_m[10] + /* in.z = 1 */ scop->proj_m[14];
// 	float w = in.x * scop->proj_m[3] + in.y * scop->proj_m[7] + in.z * scop->proj_m[11] + /* in.z = 1 */ scop->proj_m[15];

// 	if (w != 1)
// 	{
// 		out.x /= w; 
//         out.y /= w; 
//         out.z /= w; 
// 	}
// 	return (out);
// }
