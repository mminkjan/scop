/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 17:11:21 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/09/08 15:43:04 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"


void set_vertexes(t_cop *scop)
{
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao); 
	
	static const GLfloat vt_buffer_data[] = {
   		0.0f, 0.0f, 0.0f,
   		-1.0f, -1.0f, 0.0f,
		1.0f,  -1.0, 0.0f,
        0.0f, 0.0f, 0.0f,
   		-1.0f, 1.0f, 0.0f,
		1.0f, 1.0, 0.0f,
		};

	// glGenVertexArrays(1, &VAO);  
	glGenBuffers(1, &scop->vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, scop->vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(scop->vt_buffer_data), scop->vt_buffer_data, GL_STATIC_DRAW);
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
		glClearColor(0.f,0.f,0.2,0.f);
        struct timespec time;
        clock_gettime(CLOCK_MONOTONIC_RAW, &time);
        time.tv_nsec /= 10;
    	glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(scop->program_id);
  
    // update the uniform color;
        // float blueValue = sin(time.tv_nsec) / 2.0f + 0.5f;
        // // printf("%lld\n", time.tv_sec);
        // int vertexColorLocation = glGetUniformLocation(scop->program_id, "mColor");
        // glUniform4f(vertexColorLocation, 0.0f, 0.f, blueValue, 1.0f);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, scop->vertex_buffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,  0, NULL);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glDisableVertexAttribArray(0);
    	SDL_GL_SwapWindow(scop->window);
	}
}