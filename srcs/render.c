/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 17:11:21 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/05/07 19:30:07 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void set_vertexes(t_cop *scop)
{
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
        	if (e.type == SDL_KEYDOWN)
            	quit = true;
        	if (e.type == SDL_MOUSEBUTTONDOWN)
          		quit = true;
        }
		// glViewport(0, 0, WIDTH, HEIGHT);
   		// glClearColor(7.f, 1.f, 1.f, 0.f);
    	// glClear(GL_COLOR_BUFFER_BIT);
    	// SDL_GL_SwapWindow(scop->window);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, scop->vertex_buffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
	}
}