/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 17:11:21 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/09/22 18:14:10 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"


void set_vertexes(t_cop *scop)
{
	GLuint vt_array_id;

	glGenVertexArrays(1, &vt_array_id);
	glBindVertexArray(vt_array_id); 
	
	static  GLfloat vt_buffer_data[] = {
   -0.5f,-0.5f,-0.5f, // triangle 0.5 begin
    -0.5f,-0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f, // triangle 0.5 end
    0.5f, 0.5f,-0.5f, // triangle 2 : begin
    -0.5f,-0.5f,-0.5f,
    -0.5f, 0.5f,-0.5f, // triangle 2 : end
    0.5f,-0.5f, 0.5f,
    -0.5f,-0.5f,-0.5f,
    0.5f,-0.5f,-0.5f,
    0.5f, 0.5f,-0.5f,
    0.5f,-0.5f,-0.5f,
    -0.5f,-0.5f,-0.5f,
    -0.5f,-0.5f,-0.5f,
    -0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f,-0.5f,
    0.5f,-0.5f, 0.5f,
    -0.5f,-0.5f, 0.5f,
    -0.5f,-0.5f,-0.5f,
    -0.5f, 0.5f, 0.5f,
    -0.5f,-0.5f, 0.5f,
    0.5f,-0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,
    0.5f,-0.5f,-0.5f,
    0.5f, 0.5f,-0.5f,
    0.5f,-0.5f,-0.5f,
    0.5f, 0.5f, 0.5f,
    0.5f,-0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,
    0.5f, 0.5f,-0.5f,
    -0.5f, 0.5f,-0.5f,
    0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f,-0.5f,
    -0.5f, 0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f,
    0.5f,-0.5f, 0.5f
	};

    for (int i = 0; i < (12 * 3); i++)
    {
        // printf("1 %f\n", vt_buffer_data[i]);
        t_vec3 vector;
        vector.x = vt_buffer_data[3*i+0];
        vector.y = vt_buffer_data[3*i+1];
        vector.z = vt_buffer_data[3*i+2];
        iso_projection(&vector);
        vt_buffer_data[3*i+0] = vector.x;
        vt_buffer_data[3*i+1] = vector.y;
        vt_buffer_data[3*i+2] = vector.z;
        // printf("2 %f\n", vt_buffer_data[i]);
    }

	//glGenVertexArrays(1, &VAO);  
	glGenBuffers(1, &scop->vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, scop->vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vt_buffer_data), vt_buffer_data, GL_STATIC_DRAW);

    static  GLfloat g_color_buffer_data[] = {
    0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,
    0.822f,  0.569f,  0.201f,
    0.435f,  0.602f,  0.223f,
    0.310f,  0.747f,  0.185f,
    0.597f,  0.770f,  0.761f,
    0.559f,  0.436f,  0.730f,
    0.359f,  0.583f,  0.152f,
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,
    0.014f,  0.184f,  0.576f,
    0.771f,  0.328f,  0.970f,
    0.406f,  0.615f,  0.116f,
    0.676f,  0.977f,  0.133f,
    0.971f,  0.572f,  0.833f,
    0.140f,  0.616f,  0.489f,
    0.997f,  0.513f,  0.064f,
    0.945f,  0.719f,  0.592f,
    0.543f,  0.021f,  0.978f,
    0.279f,  0.317f,  0.505f,
    0.167f,  0.620f,  0.077f,
    0.347f,  0.857f,  0.137f,
    0.055f,  0.953f,  0.042f,
    0.714f,  0.505f,  0.345f,
    0.783f,  0.290f,  0.734f,
    0.722f,  0.645f,  0.174f,
    0.302f,  0.455f,  0.848f,
    0.225f,  0.587f,  0.040f,
    0.517f,  0.713f,  0.338f,
    0.053f,  0.959f,  0.120f,
    0.393f,  0.621f,  0.362f,
    0.673f,  0.211f,  0.457f,
    0.820f,  0.883f,  0.371f,
    0.982f,  0.099f,  0.879f
    };


    for (int i = 0; i < (12 * 3); i++)
    {
        float t = (float)rand()/(float)RAND_MAX;
        g_color_buffer_data[3*i+0] = 9*(1-t)*t*t*t;
        g_color_buffer_data[3*i+1] = 15*(1-t)*(1-t)*t*t;
        g_color_buffer_data[3*i+2] = 8.5*(1-t)*(1-t)*(1-t)*t;
        // printf("%f, %f, %f\n",  g_color_buffer_data[3*i+0], g_color_buffer_data[3*i+1], g_color_buffer_data[3*i+2]);
    }

    glGenBuffers(1, &scop->color_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, scop->color_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
}

void	render(t_cop *scop)
{
	SDL_Event e;
	bool quit = false;
    double	time;

	set_vertexes(scop);
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
		glBindBuffer(GL_ARRAY_BUFFER, scop->vertex_buffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,  0, NULL);

        glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, scop->color_buffer);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  0, NULL);
        
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
		glDrawArrays(GL_TRIANGLES, 0, 12*3);
		glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
    	SDL_GL_SwapWindow(scop->window);
	}
}