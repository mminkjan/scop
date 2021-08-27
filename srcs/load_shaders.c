/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_shaders.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 00:39:47 by mminkjan      #+#    #+#                 */
/*   Updated: 2021/08/27 15:49:04 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/scop.h"


void get_shader_info(t_cop *scop, GLuint shader, GLuint type)
{
    if( glIsShader( shader ) )
    {
        char    *info;
        int     info_length;
        int     max_length;
        
        info_length = 0;
        max_length = 0;
        glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &max_length );
        info = (char*)malloc(sizeof(char) * max_length);
        glGetShaderInfoLog( shader, max_length, &info_length, info);
        if( info_length > 0 )
            ft_putendl(info);
        free(info);
    }
    if (type ==  GL_VERTEX_SHADER)
        scop_return_error(scop, "vertex shader is not recognized");
    scop_return_error(scop, "fragment shader is not recognized");
}

void    compile_shader(t_cop *scop, const char **shader,  GLuint type)
{
    GLint   is_compiled;
    GLuint  shader_id;
    
    is_compiled = GL_FALSE;
    shader_id = glCreateShader(type);
    glShaderSource(shader_id, 1, &*shader, NULL);
    glCompileShader(shader_id);
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &is_compiled);
    if(is_compiled != GL_TRUE)
    {
        ft_putendl(*shader);
        get_shader_info(scop, shader_id, type);
    }
    glAttachShader(scop->program_id, shader_id);
    glLinkProgram(scop->program_id);
	glDeleteShader(shader_id);
}

void    file_to_string(t_cop *scop, int fd, const char **file)
{
    int return_value;
    char *line;
    char *buffer;
    char *temp;
    
    return_value = get_next_line(fd, &line);
    buffer = (char*)malloc(sizeof(char) * 1000000);
    ft_bzero(buffer, ft_strlen(buffer));
    while (return_value > 0)
    {
        temp = ft_strjoin(buffer, line);
        buffer = ft_strcpy(buffer, temp);
        if (temp != NULL)
            free(temp);
        free(line);
        return_value = get_next_line(fd, &line);
    }
    if (return_value < 0)
        scop_return_error(scop, "unable to read shader\n");
    *file = ft_strdup(buffer);
    if (*file == NULL)
        scop_return_error(scop, "unable to save shader\n");
    free(buffer);
}

GLuint load_shaders(t_cop *scop)
{
    int fd;
    const char *vshader;
    const char *fshader;
    
    fd = open("resources/shaders/basic.vertexshader", O_RDONLY);
    if (fd == -1)
        scop_return_error(scop, "unable to open vertex shader\n");
    file_to_string(scop, fd, &vshader);
    compile_shader(scop, &vshader, GL_VERTEX_SHADER);
    free((void*)vshader);
    close(fd);
    fd = open("resources/shaders/basic.fragmentshader", O_RDONLY);
    if (fd == -1)
        scop_return_error(scop, "unable to open fragment shader\n");
    file_to_string(scop, fd, &fshader);
    compile_shader(scop, &fshader, GL_FRAGMENT_SHADER);
    free((void*)fshader);
    close(fd);
    return (0);
}

