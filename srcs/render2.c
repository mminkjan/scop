/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 12:10:39 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/10/19 19:35:54 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"
 
void	create_object(t_cop *scop)
{
	GLfloat		v_edit[scop->obj.v_length];
	GLfloat		c_buffer[scop->obj.v_length];
	GLushort	i_buffer[scop->obj.i_length];
	
	glGenVertexArrays(1, &scop->VAO);
	glBindVertexArray(scop->VAO);

	//vertex buffer
	for (int i = 0; i < (scop->obj.v_length / 3); i++)
    {
        t_vec3 vector;
        vector.x = scop->obj.v[3*i+0] / 3;
        vector.y = scop->obj.v[3*i+1] / 3;
        vector.z = scop->obj.v[3*i+2] / 3;
        // iso_projection(&vector);
        v_edit[3*i+0] = vector.x;
       	v_edit[3*i+1] = vector.y;
        v_edit[3*i+2] = vector.z;
		// printf("%f : %f : %f\n", vector.x, vector.y, vector.z);

    }

	glGenBuffers(1, &scop->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, scop->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * scop->obj.vt_length, v_edit, GL_STATIC_DRAW);

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

void	render(t_cop *scop)
{
	bool quit = false;
	SDL_Event 	e;
	
	create_object(scop);
	printf("%u\n", scop->obj.i_length);
	while (!quit)
	{
		//set environmemt
		glUseProgram(scop->program_id);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
		
		//enable vertex array
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, scop->VBO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		//enable color array
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, scop->CBO);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		//draw elememts
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scop->IBO);

		// if (scop->triangle_fan == true)
		// {
		// 	printf("traingle_fam\n");
		// 	glDrawElements(GL_TRIANGLE_FAN, sizeof(GLushort) * scop->obj.i_length, GL_UNSIGNED_SHORT, NULL);
		// }
		// else if (scop->line == true) {
		// 	printf("line\n");
		// 	glDrawElements(GL_LINES, sizeof(GLushort) * scop->obj.i_length, GL_UNSIGNED_SHORT, (void*)0); 
		// }
		// else {
		// 	// printf("normal\n");
		glDrawElements(GL_TRIANGLES, sizeof(GLushort) * scop->obj.i_length, GL_UNSIGNED_SHORT, (void*)0);
		// }
	
		//disable pointers to shaders?s
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