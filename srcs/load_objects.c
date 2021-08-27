/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_objects.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 13:26:34 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/08/27 22:20:36 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"

// void arrange_vertices(t_cop *scop, t_vec3 *vertices, t_vec4 *faces, )
// {
    
// }

t_vec4 get_obj_faces(t_cop *scop, const char *obj, int *index)
{
    t_vec4 face;
    int     i;

    i = *index;;
    i += 2;
    face.x = (float)ft_atoii(obj, &i);
    i++;
    face.y = (float)ft_atoii(obj, &i);
    i++;
    face.z = (float)ft_atoii(obj, &i);
    i++;
    if (ft_isdigit(obj[i]) > 0)
        face.w = (float)ft_atoii(obj, &i);
    else
        face.w = -1;
    printf("%f, %f, %f, %f\n", face.x, face.y, face.z, face.w);
    *index = i;
    return (face);
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

t_vec3 get_obj_vertices(t_cop *scop, const char *obj, int *index)
{
    t_vec3      vertex;
    int         i;
    int v;
    
    i = *index;
    i += 2;
    vertex.x = get_float_value(scop, obj, &i);
    i++;
    vertex.y = get_float_value(scop, obj, &i);
    i++;
    vertex.z = get_float_value(scop, obj, &i);
    printf("%f, %f, %f\n", vertex.x, vertex.y, vertex.z);
    *index = i - 1;
    return (vertex);
}

void save_obj_vertices(t_cop *scop, const char *obj)
{
    int         i;
    int         v;
    int         f;
    t_vec3      bufferv[100000];
    t_vec4      bufferf[100000];
    

    i = 0;
    v = 0;
    f = 0;
    while (obj[i] != '\0')
    {
        if (obj[i] == 'v' && obj[i + 1] == ' ')
        {
            bufferv[v] = get_obj_vertices(scop, obj, &i);
            v++;
        }
        if (obj[i] == 'f' && obj[i + 1] == ' ')
        {
            bufferf[f] = get_obj_faces(scop, obj, &i);
            f++;
        }
        // arrange_vertices(bufferv, bufferf, v, f);
        // set_ob
        i++;
    }
}

void load_objects(t_cop *scop)
{
    int fd;
    const char *obj_file;

    fd = open("resources/models/42.obj", O_RDONLY);
    if (fd == -1)
        scop_return_error(scop, "unable to open object file\n");
    file_to_string(scop, fd, &obj_file);
    save_obj_vertices(scop, obj_file);
    printf("%s\n", obj_file);
}