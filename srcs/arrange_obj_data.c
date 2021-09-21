/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arrange_obj_data.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 14:56:24 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/09/08 17:40:01 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"


void 

void arrange_vertices_triangle(t_cop *scop, t_vec3 *vertices, t_vec4 *faces, int fc_lenght)
{
    int vt_i;
    int fcs_i;
    t_vec4 face;
    t_vec3 vertex;


    vt_i = 0;
    fcs_i = 0;

    while (fcs_i < fc_lenght)
    {
        face = faces[fcs_i];
        vertex = face.x;
        set_vt_buffer(scop_>vt_buffer_data, vt_i, vertex)
        scop->vt_buffer_data[vt_i] = vertex.x;
        scop->vt_buffer_data[vt_i + 1] = vertex.y;
        scop->vt_buffer_data[vt_i + 2] = vertex.z;
        vertex
        fcs_i++;
        vt_i += 3;
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