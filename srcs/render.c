/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 17:11:21 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/10/19 12:10:15 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/scop.h"


void init_VAO(t_cop *scop)
{
	GLfloat v_edit[scop->obj.v_length];
	GLfloat	c_buffer[scop->obj.v_length];

	glGenVertexArrays(1, &scop->VAO);
	glBindVertexArray(scop->VAO);

	glGenBuffers(1, &scop->IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scop->IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, scop->obj.i_length, scop->obj.i, GL_STATIC_DRAW);
	
	
    for (int i = 0; i < (scop->obj.v_length / 3); i++)
    {
        t_vec3 vector;
        vector.x = scop->obj.v[3*i+0] / 2;
        vector.y = scop->obj.v[3*i+1] / 2;
        vector.z = scop->obj.v[3*i+2] / 2;
        iso_projection(&vector);
        v_edit[3*i+0] = vector.x;
       	v_edit[3*i+1] = vector.y;
        v_edit[3*i+2] = vector.z;
    }

	glGenBuffers(1, &scop->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, scop->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(v_edit), v_edit, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    for (int i = 0; i < (scop->obj.v_length / 3); i++)
    {
        float t = (float)rand()/(float)RAND_MAX;
        c_buffer[3*i+0] = 9*(1-t)*t*t*t;
        c_buffer[3*i+1] = 15*(1-t)*(1-t)*t*t;
        c_buffer[3*i+2] = 8.5*(1-t)*(1-t)*(1-t)*t;
        // printf("%f, %f, %f\n",  g_color_buffer_data[3*i+0], g_color_buffer_data[3*i+1], g_color_buffer_data[3*i+2]);
    }

    glGenBuffers(1, &scop->CBO);
    glBindBuffer(GL_ARRAY_BUFFER, scop->CBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(c_buffer), c_buffer, GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}



void	render(t_cop *scop)
{
	SDL_Event e;
	bool quit = false;
	GLuint	tr_array_id;
	GLuint	qd_array_id;


	init_VAO(scop);
	while (!quit)
	{
    	while (SDL_PollEvent(&e))
		{
        	if (e.type == SDL_QUIT)
            	quit = true;
        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(scop->program_id);
		
		// glBindVertexArray(scop->VAO);
		// glBindBuffer(GL_ARRAY_BUFFER, scop->VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scop->IBO);
		// glEnableVertexAttribArray(0);
		// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), NULL);
		glDrawElements(GL_TRIANGLES, scop->obj.i_length, GL_UNSIGNED_SHORT, (void*)0);
		// glBindBuffer(GL_ARRAY_BUFFER, scop->vt_array_tr);
		// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,  0, NULL);
		// glBindBuffer(GL_ARRAY_BUFFER, scop->CBO);
        // glEnableVertexAttribArray(1);
		// glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), NULL);
		// glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  0, NULL);
        
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
		// glDisableVertexAttribArray(0);
        // glDisableVertexAttribArray(1);
    	SDL_GL_SwapWindow(scop->window);
	}
}