/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 17:11:21 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/10/06 15:46:41 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

GLuint save_buffer_datat(t_cop *scop)
{
	GLuint VBO_size;
	GLuint VBO;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	VBO_size = scop->obj_data.points_lenght * scop->obj_data.lines_lenght * \
		scop->obj_data.triangles_lenght * scop->obj_data.quads_lenght;
	glBufferData(GL_ARRAY_BUFFER, VBO_size, 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, scop->obj_data.triangles_lenght, scop->obj_data.triangles);
	glBufferSubData(GL_ARRAY_BUFFER, scop->obj_data.triangles_lenght, scop->obj_data.quads_lenght, scop->obj_quads.triangles);
	
    for (int i = 0; i < (scop->obj_data.triangles_lenght / 3); i++)
    {
        t_vec3 vector;
        vector.x = scop->obj_data.triangles[3*i+0] / 4;
        vector.y = scop->obj_data.triangles[3*i+1] / 4;
        vector.z = scop->obj_data.triangles[3*i+2] / 4;
        iso_projection(&vector);
        vt_buffer_data[3*i+0] = vector.x;
       	vt_buffer_data[3*i+1] = vector.y;
        vt_buffer_data[3*i+2] = vector.z;
    }

	glGenBuffers(1, &scop->vt_array_tr);
	glBindBuffer(GL_ARRAY_BUFFER, scop->vt_array_tr);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vt_buffer_data), vt_buffer_data, GL_STATIC_DRAW);


    GLfloat g_color_buffer_data[scop->obj_data.triangles_lenght];
    for (int i = 0; i < (scop->obj_data.triangles_lenght / 3); i++)
    {
        float t = (float)rand()/(float)RAND_MAX;
        g_color_buffer_data[3*i+0] = 9*(1-t)*t*t*t;
        g_color_buffer_data[3*i+1] = 15*(1-t)*(1-t)*t*t;
        g_color_buffer_data[3*i+2] = 8.5*(1-t)*(1-t)*(1-t)*t;
        // printf("%f, %f, %f\n",  g_color_buffer_data[3*i+0], g_color_buffer_data[3*i+1], g_color_buffer_data[3*i+2]);
    }

    glGenBuffers(1, &scop->color_buffer1);
    glBindBuffer(GL_ARRAY_BUFFER, scop->color_buffer1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
	return (tr_array_id);
}



void	render(t_cop *scop)
{
	SDL_Event e;
	bool quit = false;
	GLuint	VBO;

 
	glGenBuffers(1, &VBO);
	if (scop->obj_data.triangles_lenght > 0)
		create_array_buffer_triangles(scop, VBO);
	if (scop->obj_data.triangles_lenght > 0)
		qd_array_id = create_array_buffer_triangles(scop);
	while (!quit)
	{
    	while (SDL_PollEvent(&e))
		{
        	if (e.type == SDL_QUIT)
            	quit = true;
        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(scop->program_id);
		
		glBindVertexArray(tr_array_id);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, scop->vt_array_tr);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,  0, NULL);
        glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, scop->color_buffer1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  0, NULL);
		glDrawArrays(GL_TRIANGLES, 0, scop->obj_data.triangles_lenght);

		glBindVertexArray(qd_array_id);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, scop->vt_array_qd);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,  0, NULL);
        glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, scop->color_buffer2);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  0, NULL);
		glDrawArrays(GL_TRIANGLE_FAN, 0, scop->obj_data.quads_lenght);
        
        // glEnable(GL_DEPTH_TEST);
        // glDepthFunc(GL_LESS);
		// glDisableVertexAttribArray(0);
        // glDisableVertexAttribArray(1);
    	SDL_GL_SwapWindow(scop->window);
	}
}