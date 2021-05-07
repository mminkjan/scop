/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   SDL_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 17:08:44 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/05/07 19:28:28 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"


void	SDL_GL_init(t_cop *scop)	
{
	GLuint VertexArrayID;
	GLenum err;


	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5 );
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1 );
	scop->window = SDL_CreateWindow(WINDOW_NAME, \
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	if (scop->window == NULL)
		scop_return_error(scop, SDL_GetError());
	SDL_GL_CreateContext(scop->window);
	glewExperimental = GL_TRUE; 
	err = glewInit();
	if (GLEW_OK != err)
		scop_return_error(scop, "Unable to initialize glew");
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
}