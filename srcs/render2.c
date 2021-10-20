/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 12:10:39 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/10/20 14:53:36 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"
 
void	gen_object(t_cop *scop)
{
	GLfloat		v_edit[scop->obj.v_length];
	GLfloat		c_buffer[scop->obj.v_length];
	GLushort	i_buffer[scop->obj.i_length];
    t_vec3		vector;
	
	glGenVertexArrays(1, &scop->VAO);
	glBindVertexArray(scop->VAO);

	//vertex buffer
	glGenBuffers(1, &scop->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, scop->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * scop->obj.v_length, scop->obj.v, GL_DYNAMIC_DRAW);

	//color buffer
	for (int i = 0; i < (scop->obj.v_length / 3); i++)
    {
        float t = (float)rand()/(float)RAND_MAX;
        c_buffer[3*i+0] = 9*(1-t)*t*t*t;
        c_buffer[3*i+1] = 15*(1-t)*(1-t)*t*t;
        c_buffer[3*i+2] = 8.5*(1-t)*(1-t)*(1-t)*t;
    }

    glGenBuffers(1, &scop->CBO);
    glBindBuffer(GL_ARRAY_BUFFER, scop->CBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(c_buffer), c_buffer, GL_STATIC_DRAW);

	//index buffer
	glGenBuffers(1, &scop->IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scop->IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort) * scop->obj.i_length, scop->obj.i, GL_STATIC_DRAW);

}

static void bind_arrays(t_cop *scop)
{
	//enable vertex array
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, scop->VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	//enable color array
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, scop->CBO);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scop->IBO);
}

void	render(t_cop *scop)
{
	bool quit = false;
	SDL_Event 	e;
	
	gen_object(scop);
	printf("%u\n", scop->obj.i_length);
	while (!quit)
	{
		//set environmemt
		glUseProgram(scop->program_id);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

		obj_transform(scop);
		bind_arrays(scop);

		//draw elememts
		glDrawElements(GL_TRIANGLES, sizeof(GLushort) * scop->obj.i_length, GL_UNSIGNED_SHORT, (void*)0);
	
		//disable pointers to shaders?
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		SDL_GL_SwapWindow(scop->window);
		while (SDL_PollEvent(&e))
		{
        	if (e.type == SDL_QUIT)
            	quit = true;
        }
	}
}