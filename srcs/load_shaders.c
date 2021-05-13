/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_shaders.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 00:39:47 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/05/13 18:20:33 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"

void    shader_to_string(t_cop *scop, int fd)
{
    int return_value;
    char *line;
    char *buffer;
    char *temp;
    return_value = get_next_line2(fd, &line);
    buffer = (char*)malloc(sizeof(char) * 1000);
    while (return_value > 0)
    {
        temp = ft_strjoin(buffer, line);
        buffer = ft_strcpy(buffer, temp);
        if (temp != NULL)
            free(temp);
        free(line);
        return_value = get_next_line2(fd, &line);
    }
    if (return_value < 0)
        scop_return_error(scop, "unable to read vertex shader\n");
    scop->shaders->vshader = ft_strdup(buffer);
    free(buffer);
}

GLuint load_shaders(t_cop *scop)
{
    GLuint shader_id_vertex;
    GLuint shader_id_fragment;
    char   *vshader;
    char    *fshader;   
    int fd;

    shader_id_vertex = glCreateShader(GL_VERTEX_SHADER);
    shader_id_fragment = glCreateShader(GL_FRAGMENT_SHADER);
    fd = open("resources/shaders/basic.vertexshader", O_RDONLY);
    if (fd == -1)
        scop_return_error(scop, "unable to open vertex shader\n");
    shader_to_string(scop, fd);
    return (0);

    //TODO: open fd read with Vertex/fragment shaderstream https://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/
}