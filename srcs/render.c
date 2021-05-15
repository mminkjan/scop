/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 17:11:21 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/05/15 15:11:39 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void set_vertexes(t_cop *scop)
{
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao); 
	
	static const GLfloat vt_buffer_data[] = {
   		-1.0f, -1.0f, 0.0f,
   		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
		};

	glGenBuffers(1, &scop->vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, scop->vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vt_buffer_data), vt_buffer_data, GL_STATIC_DRAW);
}

void	render(t_cop *scop)
{
	SDL_Event e;
	bool quit = false;

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
		glClearColor(0.f,0.f,0.f,0.f);
    	glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(scop->program_id);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, scop->vertex_buffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,  3 * sizeof(float), NULL);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
    	SDL_GL_SwapWindow(scop->window);
	}
}