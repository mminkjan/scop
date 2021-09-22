/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_arrange.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 14:56:24 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/09/22 18:08:37 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"


void set_data_vt3(t_cop *scop, t_vec4 face, t_vec3 *vertices, int index)
{
    scop->vt3_buffer_data[index] = vertices[face.x].x;
    scop->vt3_buffer_data[index + 1] = vertices[face.x].y;
    scop->vt3_buffer_data[index + 2] = vertices[face.x].z;
    scop->vt3_buffer_data[index + 3] = vertices[face.y].x;
    scop->vt3_buffer_data[index + 4] = vertices[face.y].y;
    scop->vt3_buffer_data[index + 5] = vertices[face.y].z;
    scop->vt3_buffer_data[index + 6] = vertices[face.z].x;
    scop->vt3_buffer_data[index + 7] = vertices[face.z].y;
    scop->vt3_buffer_data[index + 8] = vertices[face.z].z;

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