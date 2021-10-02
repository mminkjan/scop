/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 17:11:21 by mminkjan      #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2021/09/26 23:50:41 by mminkjan      ########   odam.nl         */
=======
/*   Updated: 2021/10/02 18:17:55 by mminkjan      ########   odam.nl         */
>>>>>>> b5cf5fe7dcd5b01626d654e190426dc5e6a12190
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void create_array_buffer_quads(t_cop *scop)
{
	GLfloat vt_buffer_data[scop->obj_data.quads_lenght];

	for (int i = 0; i < (scop->obj_data.quads_lenght / 4); i++)
    {
        t_vec3 vector;
        vector.x = scop->obj_data.quads[3*i+0] / 2;
        vector.y = scop->obj_data.quads[3*i+1] / 2;
        vector.z = scop->obj_data.quads[3*i+2] / 2;
        iso_projection(&vector);
        vt_buffer_data[3*i+0] = vector.x;
       	vt_buffer_data[3*i+1] = vector.y;
        vt_buffer_data[3*i+2] = vector.z;
    }

	glGenBuffers(1, &scop->quads_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, scop->quads_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vt_buffer_data), vt_buffer_data, GL_STATIC_DRAW);

	GLfloat g_color_buffer_data[scop->obj_data.quads_lenght];
    for (int i = 0; i < (scop->obj_data.quads_lenght / 4); i++)
    {
        float t = (float)rand()/(float)RAND_MAX;
        g_color_buffer_data[3*i+0] = 9*(1-t)*t*t*t;
        g_color_buffer_data[3*i+1] = 15*(1-t)*(1-t)*t*t;
        g_color_buffer_data[3*i+2] = 8.5*(1-t)*(1-t)*(1-t)*t;
        // printf("%f, %f, %f\n",  g_color_buffer_data[3*i+0], g_color_buffer_data[3*i+1], g_color_buffer_data[3*i+2]);
    }

    glGenBuffers(1, &scop->color_buffer2);
    glBindBuffer(GL_ARRAY_BUFFER, scop->color_buffer2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
}


void create_array_buffer_trianges(t_cop *scop)
{
	GLfloat vt_buffer_data[scop->obj_data.triangles_lenght];
	
    for (int i = 0; i < (scop->obj_data.triangles_lenght / 3); i++)
    {
        t_vec3 vector;
<<<<<<< HEAD
        vector.x = scop->triangle_data[3*i+0] / 2;
        vector.y = scop->triangle_data[3*i+1] / 2;
        vector.z = scop->triangle_data[3*i+2] / 2;
=======
        vector.x = scop->obj_data.triangles[3*i+0] / 3;
        vector.y = scop->obj_data.triangles[3*i+1] / 3;
        vector.z = scop->obj_data.triangles[3*i+2] / 3;
>>>>>>> b5cf5fe7dcd5b01626d654e190426dc5e6a12190
        iso_projection(&vector);
        vt_buffer_data[3*i+0] = vector.x;
       	vt_buffer_data[3*i+1] = vector.y;
        vt_buffer_data[3*i+2] = vector.z;
    }

	glGenBuffers(1, &scop->triangles_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, scop->triangles_buffer);
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
}

void	render(t_cop *scop)
{
	GLuint vt_array_id;
	SDL_Event e;
	bool quit = false;
    double	time;
	

	// if (scop->obj_data.points_lenght > 0)
	// 	create_array_buffer_points(scop);
	// if (scop->obj_data.lines_lenght > 0)
	// 	create_array_buffer_lines(scop);
	if (scop->obj_data.triangles_lenght > 0)
		create_array_buffer_trianges(scop);
	if (scop->obj_data.quads_lenght > 0)
		create_array_buffer_quads(scop);

	
	glGenVertexArrays(4, &vt_array_id);
	glBindVertexArray(vt_array_id[0]);
	glBindVertexArray(vt_array_id[1]);
	glBindVertexArray(vt_array_id[2]);
	glBindVertexArray(vt_array_id[3]);
	
	while (!quit)
	{
    	while (SDL_PollEvent(&e))
		{
        	if (e.type == SDL_QUIT)
            	quit = true;
        	// if (e.type == SDL_KEYDOWN)
            // 	quit = true;
        	// if (e.type == SDL_MOUSEBUTTONDOWN)
          	// 	quit = true;
        }
		// glClearColor(0.f,0.f,0.2,0.f);
    	//glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(scop->program_id);
		
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, scop->triangles_buffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,  0, NULL);
		
        glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, scop->color_buffer1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  0, NULL);
		
		glEnableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, scop->quads_buffer);
		glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE,  0, NULL);

		glEnableVertexAttribArray(3);
		glBindBuffer(GL_ARRAY_BUFFER, scop->color_buffer2);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE,  0, NULL);


        
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
		glDrawArrays(GL_TRIANGLES, 0, scop->obj_data.triangles_lenght / 3);
		glDrawArrays(GL_QUADS, 2, scop->obj_data.quads_lenght / 4);
		glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
    	SDL_GL_SwapWindow(scop->window);
	}
}