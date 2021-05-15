/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   SDL_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 17:08:44 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/05/15 14:38:12 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"


void	SDL_GL_init(t_cop *scop)	
{
	GLuint VertexArrayID;
	GLenum glew_status;
	const GLubyte *str = malloc(1000);
	SDL_GLContext gl_context;
    SDL_Window	*window;



	// glGetString(GL_VERSION);
	SDL_Init(SDL_INIT_VIDEO); 
  	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	scop->window = SDL_CreateWindow(WINDOW_NAME, \
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	if (window == NULL)
		scop_return_error(scop, SDL_GetError());
	gl_context = SDL_GL_CreateContext(scop->window);
	if (gl_context == NULL)
		scop_return_error(scop, "unable to creeate GL context\n");
	// if (SDL_GL_MakeCurrent(scop->window, gl_context) == 0)
	// 	scop_return_error(scop,  SDL_GetError());
	str = glGetString(GL_VERSION);
	printf("%s\n", str);
	glewExperimental = GL_TRUE;
	glew_status = glewInit();
	if (glew_status != GLEW_OK)
		scop_return_error(scop, (const char*)glewGetErrorString(glew_status));
	scop->program_id = glCreateProgram();
	load_shaders(scop);
	// glViewport(0, 0, WIDTH, HEIGHT);
	// glGenVertexArrays(1, &VertexArrayID);
	// glBindVertexArray(VertexArrayID);
	// scop->program_id = load_shaders(scop);
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// glUseProgram(program_id);
	
}
