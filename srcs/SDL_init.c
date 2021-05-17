/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   SDL_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 17:08:44 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/05/17 19:56:36 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"


void	SDL_GL_init(t_cop *scop)	
{
    char            *buffer;
	GLenum          glew_status;
	SDL_GLContext   gl_context;
    SDL_Window      *window;

    buffer = (char*)malloc(sizeof(char) * 100);//WHHHYYYYY???
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
	glewExperimental = GL_TRUE;
	glew_status = glewInit();
	if (glew_status != GLEW_OK)
		scop_return_error(scop, (const char*)glewGetErrorString(glew_status));
	scop->program_id = glCreateProgram();
    free(buffer);
	load_shaders(scop);
}
