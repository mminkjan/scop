/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_shaders.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 00:39:47 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/05/08 00:46:35 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"

GLuint load_shaders(const *char file_vertex, const *char file_fragment)
{
    GLuint shader_id_vertex;
    GLuint shader_id_fragment;

    shader_id_vertex = glCreateShader(GL_VERTEX_SHADER);
    shader_id_fragment = glCreateShader(GL_FRAGMENT_SHADER);

    //TODO: open fd read with Vertex/fragment shaderstream https://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/
}